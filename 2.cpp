#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Backlog;

class User {
    std::string username;
    std::string role;
    std::vector<std::string> tasks;
};

class Story {
    std::string title;
    std::string description;
    std::string status;
    std::string assigned_to;
};

class Sprint {
    int sprint_number;
    time_t start_date;
    time_t end_date;
    std::vector<Story> stories;
};

class Team {
    std::string name;
    std::vector<User> members;
    std::vector<Sprint> sprints;
};

class Project {
    std::string name;
    Backlog* backlog; 
    Team team;

public:
    void manageSprints() {}
    void manageHistory() {}
};

class Backlog {
    std::vector<Story> stories;

public:
    void prioritizeStories() {}
};

int main() {
    User user;
    Story story;
    Sprint sprint;
    Team team;
    Project project;
    Backlog backlog;

    project.manageSprints();
    project.manageHistory();

    backlog.prioritizeStories();

    return 0;
}