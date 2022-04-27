#include "tournament_deme.hh"
#include <cassert>



Chromosome* TournamentDeme::tourney_select(){
    assert(pop_size > 1);
    uint tourney_size = 1;
    while (tourney_size < pop_size)
    {
        tourney_size = tourney_size * 2;
    }
    std::vector<Chromosome*> tourney_members(tourney_size);
    for (size_t i = 0; i < tourney_size; i++)
    {
        std::uniform_int_distribution<> distrib(0, pop_size-1)
        unsigned int to_extract = distrib(generator_)
        while (std::count(tourney_members.begin(), tourney_members.end(), pop_[to_extract]) != 0) { //checks if to_extract is in tourney_members already
            to_extract = distrib(generator_)
        }
        tourney_members.push_back(pop_[to_extract]);
    }
    while (tourney_members.size() > 1)
    {
        Chromosome* member0 = tourney_members[0];
        Chromosome* member1 = tourney_members[1];
        if (member0->get_fitness() >= member1 -> get_fitness())
        {
            std::erase(tourney_members, member1);
        }
        else{
            std::erase(tourney_members, member0);
        }
    }
    return tourney_members[0];

}