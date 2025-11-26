#pragma once
#include "media.h"
#include <string>
#include <vector>

class Song : public Media{

    public:
        Song(const std::string &name, const long duration, const std::vector<std::string> &genres){
            this->name = name;
            this->duration = duration;
            this->genres = genres;
        }
        
        std::string getName() override {
            return name;
        }

        long getDuration() override {
            return duration;
        }

        std::vector<std::string> getGenres() override {
            return genres;
        }
        

};