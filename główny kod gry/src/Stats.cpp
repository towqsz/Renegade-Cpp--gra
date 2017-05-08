#include "Stats.h"
#include <stdio.h>
#include <stdlib.h>



Stats::Stats()
{
    strcpy(player[0].name,"Gracz");
    player[0].lives=5;
    player[0].points=0;
    player[0].level=1;
    load();
}

void Stats::copyp (struct Player *p1, struct Player *p2)
{
    strcpy((p1->name), (p2->name));
    p1->lives=p2->lives;
    p1->points=p2->points;
    p1->level=p2->level;
}

void Stats::save()
{

    //zapis danych o graczu do pozniejszego wczytania
    FILE *plik;
    int status;
    plik=fopen("log/save.ini", "r+b");

    do
        {
        status=fread(&player[1], sizeof(player[1]), 1, plik);

        } while (strcmp(player[0].name, player[1].name) != 0 && !feof(plik));


    if (strcmp(player[0].name, player[1].name) == 0)
    {
        fseek(plik, -1*sizeof(player[0]), SEEK_CUR);
        status=fwrite(&player[0], sizeof(player[0]), 1, plik);
    } else
    {
        fclose(plik);
        plik=fopen("log/save.ini", "a+b");
        status=fwrite(&player[0], sizeof(player[0]), 1, plik);
    }

    fclose(plik);

    //rekordy
    size_t pointer;

    plik=fopen("log/records.ini", "r+b");

    do
        {
            status=fread(&player[1], sizeof(player[1]), 1, plik);
            if (status>1)
            {
                goto blad;
            }

        } while (player[0].points <= player[1].points  && !feof(plik));


    if (player[0].points > player[1].points )
    {
        fseek(plik, -1*sizeof(player[0]), SEEK_CUR);
        status=fwrite(&player[0], sizeof(player[0]), 1, plik);

        pointer=ftell(plik);

        for (int i=0 ; i<5 - pointer/sizeof(player[0]); i++)
        {
                status=fread(&player[2], sizeof(player[0]), 1, plik);

                if (status<=1 && !ferror(plik))
                    {
                        fseek(plik, -1*sizeof(player[0]), SEEK_CUR);
                        status=fwrite(&player[1], sizeof(player[0]), 1, plik);
                        copyp(&player[1], &player[2]);

                    }
        }

    }

    blad:
    fclose(plik);
}

void Stats::clear_rec()
{
    FILE *plik;
    int status;
    plik=fopen("log/records.ini", "w+b");
    strcpy(player[2].name, "Nazwa gracza");
    player[2].points=0;
    player[2].lives=0;
    player[2].level=0;

    for (int i=0 ; i<5 ; i++)
        status=fwrite(&player[2], sizeof(player[2]), 1, plik);


    fclose(plik);
}

void Stats::load()
{

    FILE *plik;
    int status, lvl;
    plik=fopen("log/settings.ini", "rb");


        status=fread(&lbl, sizeof(lbl), 1, plik);

        difficulty=lbl.level;
        strcpy(player[0].name, lbl.name);

    fclose(plik);


}

void Stats::readrec(char tab[][50])
{


    char bufor[20];
    FILE *plik;
    int status, ile=5;
    plik=fopen("log/records.ini", "r+b");
    for(int i=0 ; i<ile ; i++)
    {
        status=fread(&player[1], sizeof(player[1]), 1, plik);
        strcpy(tab[i], player[1].name);

        for (int n=0 ; n < ile ; n++ )
            strcat(tab[i], " ");
        strcat(tab[i], "-");

        sprintf(bufor, "%d", player[1].points);
        strcat(tab[i], bufor);

    }
    fclose(plik);


}

int Stats::getdifficulty()
{
    return difficulty;
}

int Stats::getpoints()
{
    return player[0].points;
}

void Stats::addpoints(int x)
{
    player[0].points+=x;
    player[0].points+=x*difficulty;
}

int Stats::getlevel()
{
    return player[0].level;
}

void Stats::addlevel()
{
    player[0].level++;
}

int Stats::getlives()
{
    return player[0].lives;
}

void Stats::sublives()
{
    player[0].lives--;
}

char *Stats::getname()
{
    return player[0].name;
}

Stats::~Stats()
{
    //dtor
}
