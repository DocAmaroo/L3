#ifndef __VERS_H
#define __VERS_H

class Vers{
    private : 
        std::string suiteMots;
        std::string rime;

    public :
        Vers();
        Vers(std::string);
        Vers(std::string, std::string);
        virtual ~Vers();

        virtual std::string getSuiteMots() const;
        virtual void setSuiteMots(std::string);
        virtual std::string getRime() const;
        virtual void setRime(std::string);
        virtual void saisie(std::istream&);
        virtual void affiche(std::ostream&) const;
};

std::ostream operator<< (std::ostream&, const Vers&);
std::istream operator>> (std::istream&, const Vers&);
#endif