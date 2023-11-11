/*
CSCI235 Fall 2023
Project 5 - Quest Management with Doubly Linked Lists
Author: Jiaxiong Guan
Date: 11/10/23

Description:
QuestList.cpp defines the constructors and public function implementation of the QuestList class
QuestList is derived from the DoublyLinkedList class and it is a list of Quest*
*/

#include "QuestList.hpp"


/**
    Default Constructor
    @post: Creates a new Quest object with default values (zero-initialized)
*/
Quest::Quest() {

    title_ = "";
    description_ = "";
    completed_ = false;
    experience_points_ = 0;
    dependencies_ = {};
    subquests_ = {};

}

/*
    @param: A reference to string reference to a quest title
    @param: A reference to string reference to a quest description
    @param: A reference to boolean representing if the quest is completed
    @param: An reference to int indicating the experience points
    @param: A reference to vector of Quest pointers representing the quest's dependencies
    @param: A reference to vector of Quest pointers representing the quest's subquests
    @post: Creates a new Quest object with the given parameters
*/
Quest::Quest(const std::string& title, const std::string& description, const bool& completed, const int& experience_points, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests) {
    
    title_ = title;
    description_ = description;
    completed_ = completed;
    experience_points_ = experience_points;
    dependencies_ = dependencies;
    subquests_ = subquests;

}

/**
    Default Constructor
*/
QuestList::QuestList() : DoublyLinkedList<Quest*>() {
}
    
/**
    @param: a reference to string name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Notes:
            - The first line of the input file is a header and should be ignored.
            - The dependencies and subquests are separated by a semicolon and may be NONE.
            - The dependencies and subquests may be in any order.
            - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
                - Title: The title of the quest
                - Description: "NOT DISCOVERED"
                - Completion Status: False
                - Experience Points: 0
                - Dependencies: An empty vector
                - Subquests: An empty vector
            - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
            Hint: update as needed using addQuest()
    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.
*/
QuestList::QuestList(const std::string& file_name) : DoublyLinkedList<Quest*>() {

    std::ifstream input_file;
    input_file.open(file_name);

    // Check if file is opened
    if(!input_file.is_open()) {
        std::cerr << "ERROR: Unable to open the CSV file." << std::endl;
    }

    // Get the header, first line
    std::string file_line;
    std::getline(input_file, file_line);

    // Getting and processing the provided csv 
    while(std::getline(input_file, file_line)) {
        // Vector to contain processed strings
        std::vector<std::string> line_parts;

        // Loop through the line and create substrings to add to vector
        for(int i = 0; i < 6; i++) {

            // Find the next comma 
            long unsigned int index = file_line.find(",");

            // If there are no more commas, add the remainder of the line to the vector
            if(index == std::string::npos)
                line_parts.push_back(file_line);

            // Else create a substr of the part before the comma, and add it to the vector, then remove the part up to the comma
            else {
                std::string processed = file_line.substr(0, index);
                file_line = file_line.substr(index + 1);
                line_parts.push_back(processed);
            }
        }

        // Creating variables for main quest construction
        std::string title = line_parts[0];
        std::string description = line_parts[1];
        bool completion = line_parts[2] == "1" ? true : false;
        int experience_points = stoi(line_parts[3]);
        std::string unproc_dependencies = line_parts[4];
        std::string unproc_subquests = line_parts[5];

        // Vectors for storing the processed string titles
        std::vector<std::string> str_dependencies;
        std::vector<std::string> str_subquests;

        // Vectors for initializing the main quest
        std::vector<Quest*> dependencies;
        std::vector<Quest*> subquests;

        
        // Int variable to store index of semicolon
        long unsigned int index = unproc_dependencies.find(";");

        // String to store quest titles
        std::string holder = "";

        // Processing dependencies and adding to vector, while there is a ";"
        while(index != std::string::npos) {

            // Store first part of the string in title and remove it from the rest of the string
            holder = unproc_dependencies.substr(0, index);
            unproc_dependencies = unproc_dependencies.substr(index + 1);
            
            // Add depdendency to string vector
            str_dependencies.push_back(holder);
            
            // Find next semicolon
            index = unproc_dependencies.find(";");
        }

        // Add last dependency
        holder = unproc_dependencies;
        if(holder == "NONE") 
            holder = "";
        else 
           str_dependencies.push_back(holder);
            
        
        // Processing subquests and adding to vector, while there is a ";"
        index = unproc_subquests.find(";");
        holder = "";
        while(index != std::string::npos) {
            
            // Store first part of the string in title and remove it from the rest of the string
            holder = unproc_subquests.substr(0, index);
            unproc_subquests = unproc_subquests.substr(index + 1);

            // Add subquest to string vector
            str_subquests.push_back(holder);
            
            // Find next semicolon
            index = unproc_subquests.find(";");
        }
        
        
        // Add last subquest
        holder = unproc_subquests;
        if(holder == "NONE") {
            holder = "";
        }
        else {
            str_subquests.push_back(holder);
        }

        // Variables for creating a "NOT DISCOVERED" Quest*
        std::string nd_title;
        std::string nd_descript = "NOT DISCOVERED";
        bool nd_completed = false;
        int nd_exp = 0;
        std::vector<Quest*> nd_vect = {};

        // Create dependency quests and add to Quest* vector
        for(long unsigned int i = 0; i < str_dependencies.size(); i++) {

            // Add the pointer directly if already in the list
            if(contains(str_dependencies[i])) {
                dependencies.push_back(getItem(getPosOf(str_dependencies[i])));
            }

            // Otherwise create a new one 
            else {
                nd_title = str_dependencies[i];
                Quest* p = new Quest(nd_title, nd_descript, nd_completed, nd_exp, nd_vect, nd_vect);
                dependencies.push_back(p);
            }
        }
        
        // Create subquests and add to Quest* vector
        for(long unsigned int i = 0; i < str_subquests.size(); i++) {
            
            // Add the pointer directly if already in the list
            if(contains(str_subquests[i])) {
                subquests.push_back(getItem(getPosOf(str_subquests[i])));
            }

            // Otherwise create a new one 
            else {
                nd_title = str_subquests[i];
                Quest* p = new Quest(nd_title, nd_descript, nd_completed, nd_exp, nd_vect, nd_vect);
                subquests.push_back(p);
            }
        }
    
        // Create a new Quest pointer and add to the list
        if(!contains(title) || getItem(getPosOf(title))->description_ == "NOT DISCOVERED") {
            
            Quest* q = new Quest(title, description, completion, experience_points, dependencies, subquests);
            addQuest(q);
        }
    }
    
    input_file.close();
}

/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& title) const{
    
    // Loop through list and find matching title
    for(long unsigned int i = 0; i < getLength(); i++) {
        if(getItem(i)->title_ == title) {
            return i;
        }
    }

    // Return -1 if not found
    return -1;

}

/**
    @param: A string reference to a quest title 
    @return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const std::string& title) const{

    // Loop through list and find matching title
    for(long unsigned int i = 0; i < getLength(); i++) {
        if(getItem(i)->title_ == title) {
            return true;
        }
    }

    // Return false if not in the QuestList
    return false;
}

/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
        
    @return: True if the quest was added or updated successfully, False otherwise
*/
bool QuestList::addQuest(Quest* quest) {
    
    // If quest is already in the list and param quest is not marked as "NOT DISCOVERED"
    if(contains(quest->title_)) {

        int pos = getPosOf(quest->title_);

        // Update if the quest is already in the list, but marked as "NOT DISCOVERED"
        if(getItem(pos)->description_ == "NOT DISCOVERED") {

            // Update quest
            getItem(pos)->description_ = quest->description_;
            getItem(pos)->completed_ = quest->completed_;
            getItem(pos)->experience_points_ = quest->experience_points_;
            getItem(pos)->dependencies_ = quest->dependencies_;
            getItem(pos)->subquests_ = quest->subquests_;
            addOtherQuests(quest);
            return true;
        }

        // If the quest is already in the list, return false
        else {
            return false;
        }
    }

    // If not already in the list, add it 
    else {
        // Insert the quest at position 0 if list is empty, otherwise insert at the end
        if(getLength() == 0)
            insert(0, quest);
        else {
            int location = getLength() + 1;
            insert(location, quest);
        }
        addOtherQuests(quest);
        return true;
    }   

    return false;
}

/**
    @param:  A reference to string representing the quest title
    @param:  A reference to string representing the quest description
    @param:  A reference to boolean representing if the quest is completed
    @param:  An reference to int representing experience points the quest rewards upon completion 
    @param:  A reference to vector of Quest pointers representing the quest's dependencies
    @param:  A reference to vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
            Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            

    @return: True if the quest was added or updated successfully, False otherwise

*/
bool QuestList::addQuest(const std::string& title, const std::string& descript, const bool& completed, const int& exp_points, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests) {
    
    // Variables for creating new Quest*
    std::string quest_title = title;
    std::string quest_descript = descript;
    bool quest_completed = completed;
    int quest_exp = exp_points;
    std::vector<Quest*> quest_dependencies = dependencies;
    std::vector<Quest*> quest_subquests = subquests;

    // Create new Quest* and add to list
    Quest* p = new Quest(quest_title, quest_descript, quest_completed, quest_exp, quest_dependencies, quest_subquests);
    if(addQuest(p))
        return true;
    else 
        return false;
}

/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* quest) {

    if(quest->dependencies_.size() == 0)
        return true;

    // Loop through vector and return false if a dependency is not completed
    for(long unsigned int i = 0; i < quest->dependencies_.size(); i++) {
        if(quest->dependencies_[i]->completed_ == false)
            return false;
    }

    // Return true if all dependencies completed
    return true;
}

/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* quest) {

    // Return true if quest is not completed and dependencies are complete
    if(!(quest->completed_) && dependenciesComplete(quest))
        return true;

       
    return false;

}

/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* quest) {
    
    // String to print out boolean "completed_" 
    std::string completed = quest->completed_ ? "Complete" : "Not Complete";
    std::cout << quest->title_ << ": " << completed << "\n" << quest->description_ << "\n\n";

}

/**
    @param: A string reference to a quest title
    @post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests. 
            The indentation for incomplete quests is 2 spaces: "  "    
            The format of the list should be of the following forms for each different case:

            Query: [Quest Title]
            No such quest.
    
            Query: [Quest Title]
            Quest Complete
    
            Query: [Quest Title]
            Ready: [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
              [Quest Title]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Quest Title]
            
    If the given quest title is not found in the list, print "No such quest."
*/
void QuestList::questQuery(const std::string& title) {

    std::cout << "Query: " << title << "\n";

    // If quest isn't in the list print "No such Quest."
    if(!contains(title))
        std::cout << "No such quest.\n";

    // If quest is complete, print "Quest Complete"
    else if(getItem(getPosOf(title))->completed_)
        std::cout << "Quest Complete\n";

    else {

        // If quest has dependencies and they aren't complete, recursively print them out 
        if(getItem(getPosOf(title))->dependencies_.size() > 0 && !dependenciesComplete(getItem(getPosOf(title)))) {
            
            // Vector for storing quest titles so recursive function doesn't print the same title multiple times
            std::vector<std::string> titles;
            titles.push_back(title);

            recursivePrintDependencies(getItem(getPosOf(title)), titles);
            std::cout << "  " << title << "\n";
        }

        // If quest has no dependencies or they are complete, then the main quest is ready 
        else if(getItem(getPosOf(title))->dependencies_.size() == 0 || dependenciesComplete(getItem(getPosOf(title)))) {
            std::cout << "Ready: " << title << "\n";
        }
    }

}

/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience() const{

    int gained_exp = 0;
    for(long unsigned int i = 0; i < getLength(); i++) {
        if(getItem(i)->completed_) {
            gained_exp += getItem(i)->experience_points_;
        }
    }
    return gained_exp;

}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(Quest* quest) {

    int projected_exp = quest->experience_points_;
    
    //If subquest vector isn't empty then recurse
    if(quest->subquests_.size() > 0) {
        for(long unsigned int i = 0; i < quest->subquests_.size(); i++) {

                projected_exp += calculateProjectedExperience(quest->subquests_[i]);    
    
        }
    }
    // If vector is empty then return the exp value
    return projected_exp;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
    Note: Also consider the experience gained if a completed subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(Quest* quest) {

    // If quest isn't completed then exp is not added
    int pathway_exp = quest->completed_ ? quest->experience_points_ : 0;
    
    // If vector is empty, then just return value
    if(quest->subquests_.size() == 0) {
        return pathway_exp;
    }

    // If subquest vector isn't empty then recurse
    else if(quest->subquests_.size() > 0) {
        for(long unsigned int i = 0; i < quest->subquests_.size(); i++) {
        
            pathway_exp += calculatePathwayExperience(quest->subquests_[i]);

        }
    }
    
    // If vector is empty then return the exp value
    return pathway_exp;
}

/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
        With filter "COMPLETE":   Only print out the completed quests in the list.
        With filter "INCOMPLETE": Only print out the incomplete quests in the list.
        With filter "AVAILABLE":  Only print out the available quests in the list.
        If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]  
    [Quest description]\n
*/
void QuestList::questHistory(const std::string& filter) {
    
    for(long unsigned int i = 0; i < getLength(); i++) {

        // String to print out boolean "completed_" 
        std::string completed = getItem(i)->completed_ ? "Complete" : "Not Complete";

        if(filter == "NONE") 
            std::cout << getItem(i)->title_ << ": " << completed << "\n" << getItem(i)->description_ << "\n";
        
        else if(filter == "COMPLETE") {

            // Check if quests have been completed
            if(completed == "Complete") 
                std::cout << getItem(i)->title_ << ": " << completed << "\n" << getItem(i)->description_ << "\n";   
        }

        else if(filter == "INCOMPLETE") {

            // Check if quests are not complete
            if(completed == "Not Complete") 
                std::cout << getItem(i)->title_ << ": " << completed << "\n" << getItem(i)->description_ << "\n";
        }

        else if(filter == "AVAILABLE") {

            // Check if quest is available
            if(questAvailable(getItem(i)))
                std::cout << getItem(i)->title_ << ": " << completed << "\n" << getItem(i)->description_ << "\n";
        }
    }

    // If filter is invalid, print "Invalid Filter"
    if(filter != "NONE" && filter != "AVAILABLE" && filter != "INCOMPLETE" && filter != "COMPLETE")
        std::cout << "Invalid Filter\n";

}

/**
    @param: A quest pointer to a main quest
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* quest) {
    
    // Calculate percent completion
    int percent_exp = 100 * calculatePathwayExperience(quest) / calculateProjectedExperience(quest);
    
    std::cout << quest->title_ << "(" << percent_exp << "% Complete)\n";

    // Print subquests if there are any
    if(quest->subquests_.size() > 0) {
        for(long unsigned int i = 0; i < quest->subquests_.size(); i++)
            recursivePrintSubquests(quest->subquests_[i], 2);
    }


}

/*
    @param: A quest pointer to a main quest
    @param: A reference to a vector of quest titles to store prinnted titles
    @post: Outputs the dependencies of the main quest that are incomplete. 
        The incomplete dependencies are printed with a double space indent "  "
        The current quest that needs to be completed is shown as "Ready: "
*/
void QuestList::recursivePrintDependencies(Quest* quest, std::vector<std::string>& titles) {
    
    // Print the quest step currently available
    if(questAvailable(quest) && quest->completed_ == false) {
        
        // Check to see if title has already been printed
        for(long unsigned int j = 0; j < titles.size(); j++) {
            if(quest->title_ == titles[j])
                return;
        }

        // Print it out as the available quest and add it to the vector
        std::cout << "Ready: " << quest->title_ << std::endl;
        titles.push_back(quest->title_);
        return;
    }

    for(long unsigned int i = 0; i < quest->dependencies_.size(); i++) {
        
        // Skip dependency if it is completed 
        if(quest->dependencies_[i]->completed_)
            continue;

        // Recurse if there are dependencies
        recursivePrintDependencies(quest->dependencies_[i], titles);

        // Don't print out completed quests
        if(!quest->completed_) {
            
            // Check to see if already printed and in vector
            for(long unsigned int j = 0; j < titles.size(); j++) {
                if(quest->title_ == titles[j]) {
                    return;
                }
            }

            // If not in vector, then print and put in vector
            std::cout << "  " << quest->title_ << "\n";
            titles.push_back(quest->title_);
        }
    }

}

/*
    @param: A quest pointer to a subquest of a main quest
    @param: An integer with the amount of indents that need to be made
    @post: Outputs the subquests of the main quest as well as completion status
        Subquests are printed with an indent of two spaces, with subquests of subquests receiving additional indents
*/
void QuestList::recursivePrintSubquests(Quest* quest, int indent) {

    // Print out indents
    for(int i = 0; i < indent; i++) {
        std::cout << " ";
    }

    std::string completed = quest->completed_ ? "Complete" : "Not Complete";
    std::cout <<  quest->title_ << ": " << completed << "\n";

    // If there are more subquests, recurse
    if(quest->subquests_.size() > 0) {

        for(long unsigned int i = 0; i < quest->subquests_.size(); i++) {

            recursivePrintSubquests(quest->subquests_[i], indent + 2);

        }
    }

}

/*
    @param: A pointer to a main quest
    @post: Loops through the main quest's subquests and dependencies to add to the list
*/
void QuestList::addOtherQuests(Quest* quest) {
    
    // Add dependencies marked as "NOT DISCOVERED"
    for(long unsigned int i = 0; i < quest->dependencies_.size(); i++) {
        
        // Skip if already in the list
        if(contains(quest->dependencies_[i]->title_)) 
            continue;
        else {
            int location = getLength() + 1;
            insert(location, quest->dependencies_[i]);
        }
    }

    // Add subquests marked as "NOT DISCOVERED"
    for(long unsigned int i = 0; i < quest->subquests_.size(); i++) {
        
        // Skip if already in the list
        if(contains(quest->subquests_[i]->title_)) 
            continue;

        else {
            int location = getLength() + 1;
            insert(location, quest->subquests_[i]);
        }
    }
}