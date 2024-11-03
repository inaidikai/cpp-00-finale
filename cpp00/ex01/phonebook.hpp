#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "contact.hpp"
class phonebook {
private:
    const int _totalNumberOfContacts;
    Contact _contactsList[8];

    void _outputPopulatedContacts(void) const;
    void _displaySingleEntryDetails(int index) const;
    int _getIndexToInsert(void) const;

public:
    phonebook(void);
    ~phonebook(void);

    void addNewEntry(void);

    
    void displayAllContacts(void) const;
    void promptAndShowEntryByIndex(void) const;
    int getNumberOfValidContacts(void) const;

};
#endif
