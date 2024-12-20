#include "Feedback.h"
#include <iostream>

Feedback::Feedback(int id, const std::string& content, int rating, const Client& client)
    : id(id), content(content), rating(rating), client(client) {
}

int Feedback::getId() const { return id; }
std::string Feedback::getContent() const { return content; }
int Feedback::getRating() const { return rating; }
Client Feedback::getClient() const { return client; }

void Feedback::setContent(const std::string& content) { this->content = content; }
void Feedback::setRating(int rating) { this->rating = rating; }
void Feedback::setClient(const Client& client) { this->client = client; }

void Feedback::printDetails() const {
    std::cout << "Feedback ID: " << id << "\n"
        << "Content: " << content << "\n"
        << "Rating: " << rating << "\n"
        << "Client: " << client.getName() << "\n";
}
