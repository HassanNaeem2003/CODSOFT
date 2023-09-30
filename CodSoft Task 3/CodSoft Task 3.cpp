#include <iostream>
#include <vector>
#include <iomanip>
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;
std::vector<std::vector<bool>> seats(NUM_ROWS, std::vector<bool>(NUM_COLS, false));
void displaySeatingChart() {
    std::cout << "   Seats" << std::endl;
    for (int row = 0; row < NUM_ROWS; ++row) 
{
    std::cout << "Row " << std::setw(2) << row + 1 << ": ";
    for (int col = 0; col < NUM_COLS; ++col) 
{
    char seatSymbol = seats[row][col] ? 'X' : '-';
    std::cout << seatSymbol << ' ';
}
    std::cout << std::endl;
}
}
bool bookSeat(int row, int col) 
{
    if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) 
{
    std::cout << "Invalid seat selection. Please try again." << std::endl;
    return false;
}
    if (seats[row - 1][col - 1]) 
{
    std::cout << "Seat already booked. Please select another seat." << std::endl;
    return false;
}
    seats[row - 1][col - 1] = true;
    return true;
}
double calculateTotalCost(int numTickets) 
{
    return numTickets * TICKET_PRICE;
}
int main() 
{
    std::cout << "Welcome to the Movie Ticket Booking System" << std::endl;
    while (true) 
{
    std::cout << "\n1. View Seating Chart\n2. Book a Ticket\n3. Exit\n";
    int choice;
    std::cin >> choice;
    switch (choice) 
{
    case 1:
    displaySeatingChart();
    break;
    case 2:
    int row, col, numTickets;
    std::cout << "Enter row and column number (e.g., 3 5): ";
    std::cin >> row >> col;
    std::cout << "Enter the number of tickets: ";
    std::cin >> numTickets;
    if (bookSeat(row, col)) 
{
    double totalCost = calculateTotalCost(numTickets);
    std::cout << "Booking successful. Total cost: $" << totalCost << std::endl;
}
    break;
    case 3:
    std::cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << std::endl;
    return 0;
    default:
    std::cout << "Invalid choice. Please try again." << std::endl;
}
}
    return 0;
}