#pragma once
#include <string>
#include "Client.h"

class Feedback {
private:
    int id;
    std::string content;
    int rating;
    Client client; 

public:
    Feedback(int id, const std::string& content, int rating, const Client& client);

    int getId() const;
    std::string getContent() const;
    int getRating() const;
    Client getClient() const;

    void setContent(const std::string& content);
    void setRating(int rating);
    void setClient(const Client& client);

    void printDetails() const;
};
