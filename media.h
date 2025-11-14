#include <string>
#include <vector>

class Media{

    protected:
        std::string name;
        long duration;
        Rating rating;
        std::vector<std::string> genres;
    
    public:
        virtual std::tring getName() = 0;
        virtual long getDuration() = 0;
        virtual Rating getRating() = 0;
        virtual std::vector<string> getGenres() = 0;
}