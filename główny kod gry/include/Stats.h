#ifndef STATS_H
#define STATS_H
#include <cstring>
#pragma once
#include "C:\Users\TSCU01\Desktop\Projekt\gr\settings\settings.h"


class Stats: public Settings
{
    public:
        Stats();
        virtual ~Stats();
        int getpoints();
        void addpoints(int x);
        int getlevel();
        int getdifficulty();
        void addlevel();
        int getlives();
        void sublives();
        char *getname();
        void save();
        void readrec(char tab[][50]);
        void clear_rec();
        Lvl lbl;

    protected:
    private:

        struct Player {
            char name[20];
            int lives;
            int points;
            int level;
        } player[3];

        int difficulty=0;
        void copyp (struct Player *p1, struct Player *p2);
        void load();
};

#endif // STATS_H
