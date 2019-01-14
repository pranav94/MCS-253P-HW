#include <iostream>
#include <fstream>
using namespace std;

#define STRMAX 100
#define SONGMAX 1024
#define DELIMITER '|'
#define LINEMAX 204

struct Song
{
    char title[STRMAX];
    char artist[STRMAX];
    int year_published;
};

struct Song music_library[SONGMAX];
int current_number_of_songs = 0;
char fileName[] = "myMusic";

int get_next_chunk_after_delimiter(char *line, int endIndex)
{
    for (; endIndex < strlen(line); endIndex++)
    {
        if (line[endIndex] == DELIMITER)
            break;
    }
    return endIndex;
}

struct Song read_song(char *line)
{
    int beginIndex, endIndex;
    char year[5];
    struct Song song = {0};

    beginIndex = endIndex = get_next_chunk_after_delimiter(line, 0);
    strncpy(song.title, line, endIndex);
    endIndex = get_next_chunk_after_delimiter(line, endIndex + 1);
    strncpy(song.artist, line + beginIndex + 1, endIndex - beginIndex - 1);
    strncpy(year, line + endIndex + 1, strlen(line) - endIndex);
    song.year_published = atoi(year);

    return song;
}

void print_song(struct Song song)
{
    cout << "Title: " << song.title << endl;
    cout << "Artist: " << song.artist << endl;
    cout << "Year Published: " << song.year_published << "\n\n";
}

void print_songs()
{
    for (int i = 0; i < current_number_of_songs; i++)
        print_song(music_library[i]);
}

void crunch_up_from_index(int index)
{
    for (int i = current_number_of_songs + 1; i > index; i--)
        music_library[i] = music_library[i - 1];
}

void crunch_down_from_index(int index)
{
    for (int i = index; i < current_number_of_songs; i++)
        music_library[i] = music_library[i + 1];
}

void add_song_to_MusicLibrary(Song song)
{
    int i = current_number_of_songs - 1;
    while (i >= 0 && (strcmp(music_library[i].title, song.title) > 0))
        i--;
    crunch_up_from_index(i + 1);
    music_library[i + 1] = song;

    current_number_of_songs++;
}

void load_MusicLibrary(char *fileName)
{
    char line[LINEMAX];
    ifstream musicLibrary;

    musicLibrary.open(fileName);
    while (musicLibrary.getline(line, LINEMAX))
        add_song_to_MusicLibrary(read_song(line));
    musicLibrary.close();
}

char read_command()
{
    char input;
    cout << "Please enter a command to continue. (i=Insert, p=Print, q=Quit, d=Delete, l=Lookup)" << endl;
    cin >> input;
    return input;
}

struct Song get_song_details()
{
    struct Song song;
    char year[5];

    cout << "Enter the title of the song: ";
    cin >> song.title;
    cout << "Enter the artist's name: ";
    cin >> song.artist;
    cout << "Enter the year of publication: ";
    cin >> year;
    song.year_published = atoi(year);

    return song;
}

void insert_song()
{
    struct Song song = get_song_details();
    add_song_to_MusicLibrary(song);
}

int binary_search(int low, int high, char *title)
{
    if (high < low)
        return -1;
    int mid = low + (high - low) / 2;
    if (strcmp(title, music_library[mid].title) == 0)
        return mid;
    if (strcmp(title, music_library[mid].title) > 0)
        return binary_search(mid + 1, high, title);
    return binary_search(low, mid - 1, title);
}

int find_index_of_song_with_name(char *name)
{
    return binary_search(0, current_number_of_songs, name);
}

void lookup_song()
{
    char title[STRMAX];
    cout << "Enter the title of the song to lookup: ";
    cin >> title;
    int index = find_index_of_song_with_name(title);
    if (index != -1)
        print_song(music_library[index]);
    else
        cout << "Song not found!\n\n";
}

void remove_song_by_index(int index, char *name)
{
    crunch_down_from_index(index);
    current_number_of_songs--;
    if (index > 0 && strcmp(music_library[index - 1].title, name) == 0)
        remove_song_by_index(index - 1, name);
    if (index < current_number_of_songs - 1 && strcmp(music_library[index + 1].title, name) == 0)
        remove_song_by_index(index + 1, name);
}

void remove_song_from_MusicLibrary_by_name(char *name)
{
    int index = find_index_of_song_with_name(name);
    int old_count = current_number_of_songs;
    if (index != -1)
        remove_song_by_index(index, name);
    else
        cout << "Song not found! ";
    cout << (old_count - current_number_of_songs) << " songs named \"" << name << "\" deleted!\n\n";
}

void delete_song()
{
    char title[STRMAX];
    cout << "Enter the title of the song to delete: ";
    cin >> title;
    remove_song_from_MusicLibrary_by_name(title);
}

void store_MusicLibrary()
{
    char line[LINEMAX];
    ofstream musicLibrary;

    musicLibrary.open(fileName);
    for (int i = 0; i < current_number_of_songs; i++)
        musicLibrary << music_library[i].title << DELIMITER << music_library[i].artist << DELIMITER << music_library[i].year_published << endl;
    musicLibrary.close();
}

void evaluate_command(char command)
{
    switch (command)
    {
    case 'i':
    case 'I':
        cout << "Insert a new song:" << endl;
        insert_song();
        break;

    case 'p':
    case 'P':
        print_songs();
        break;

    case 'l':
    case 'L':
        lookup_song();
        break;

    case 'd':
    case 'D':
        delete_song();
        break;

    case 'q':
    case 'Q':
        store_MusicLibrary();
        cout << "Thank you for using this MusicLibrary!" << endl;
        exit(0);
        break;

    default:
        cout << "Invalid command. Please try again!" << endl;
        break;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        strcpy(fileName, argv[1]);

    cout << "\nWelcome to your Music Library: " << fileName << "!\n\n";
    load_MusicLibrary(fileName);
    for (;;)
        evaluate_command(read_command());

    return 0;
}