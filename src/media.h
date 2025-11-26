#pragma once
#include <string>
#include <vector>

#include "rating.h"

class Media{

    protected:
        std::string name;
        long duration = -1L;
        std::vector<std::string> genres;
    
    public:
        virtual std::string getName() = 0;
        virtual long getDuration() = 0;
        virtual std::vector<std::string> getGenres() = 0;

};