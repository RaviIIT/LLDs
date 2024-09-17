#include <bits/stdc++.h>
using namespace std;

// Movie class
class Movie
{
public:
    int id;
    string title;

    Movie(int id, string title) : id(id), title(title) {}
};

// Theater class
class Theater
{
public:
    int id;
    string name;
    vector<Movie *> movies;
    map<int, int> availableSeats;

    Theater(int id, string name) : id(id), name(name) {}

    // Add a movie to the theater
    void addMovie(Movie *movie, int seatCount)
    {
        movies.push_back(movie);
        availableSeats[movie->id] = seatCount;
    }

    // Display the list of movies playing in this theater
    void displayMovies()
    {
        cout << "Movies playing in theater: " << name << endl;
        for (auto &movie : movies)
        {
            cout << "Movie ID: " << movie->id << ", Title: " << movie->title << endl;
        }
    }

    // Check if seats are available
    bool hasAvailableSeats(Movie *movie)
    {
        return availableSeats[movie->id] > 0;
    }

    // Book a seat
    void bookSeat(Movie *movie)
    {
        if (hasAvailableSeats(movie))
        {
            availableSeats[movie->id]--;
            cout << "Booking successful! Seats remaining: " << availableSeats[movie->id] << endl;
        }
        else
        {
            cout << "No seats available!" << endl;
        }
    }
};

// BookingSystem class
class BookingSystem
{
public:
    vector<Theater *> theaters;

    // Add a theater to the system
    void addTheater(Theater *theater)
    {
        theaters.push_back(theater);
    }

    // Display all theaters
    void displayTheaters()
    {
        cout << "Available theaters:\n";
        for (auto &theater : theaters)
        {
            cout << "Theater ID: " << theater->id << ", Name: " << theater->name << endl;
        }
    }

    // View movies in a selected theater
    void viewMoviesInTheater(int theaterId)
    {
        for (auto &theater : theaters)
        {
            if (theater->id == theaterId)
            {
                theater->displayMovies();
                return;
            }
        }
        cout << "Theater not found!" << endl;
    }

    // Book tickets for a movie
    void bookTicket(int theaterId, int movieId)
    {
        for (auto &theater : theaters)
        {
            if (theater->id == theaterId)
            {
                for (auto &movie : theater->movies)
                {
                    if (movie->id == movieId)
                    {
                        if (theater->hasAvailableSeats(movie))
                        {
                            theater->bookSeat(movie);
                            return;
                        }
                        else
                        {
                            cout << "No seats available for this movie!" << endl;
                            return;
                        }
                    }
                }
                cout << "Movie not found in this theater!" << endl;
                return;
            }
        }
        cout << "Theater not found!" << endl;
    }
};

// Main function for demonstration
int main()
{
    BookingSystem system;

    // Create movies
    Movie *movie1 = new Movie(1, "Avengers");
    Movie *movie2 = new Movie(2, "Inception");

    // Create theaters and add movies
    Theater *theater1 = new Theater(1, "PVR Cinemas");
    Theater *theater2 = new Theater(2, "INOX");
    theater1->addMovie(movie1, 10);
    theater1->addMovie(movie2, 10);
    theater2->addMovie(movie2, 10);

    // Add theaters to booking system
    system.addTheater(theater1);
    system.addTheater(theater2);

    // Display theaters
    system.displayTheaters();

    // View movies in theater 1
    system.viewMoviesInTheater(1);

    // Book a ticket for Avengers in PVR Cinemas
    system.bookTicket(1, 1);

    // Attempt to book again
    system.bookTicket(1, 1);

    return 0;
}