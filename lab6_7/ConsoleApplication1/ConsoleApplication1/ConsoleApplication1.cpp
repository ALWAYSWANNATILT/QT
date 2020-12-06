#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Eyes
{
public:
    string Color;
    string Figure;
    Eyes(string color, string figure) 
    {
        this->Color = color;
        this->Figure = figure;
    };
    void info() {
        cout << this->Color << " " << this->Figure << " Eyes"  << endl;

    }
};

class Nose
{
public:
    string Color;
    string Figure;
    Nose(string color, string figure)
    {
        this->Color = color;
        this->Figure = figure;
    };
    void info() {
        cout <<  this->Color << " " << this->Figure << " Nose " << endl;
    }
};

class Mouth
{
public:
    string Color;
    string Figure;
    Mouth(string color, string figure)
    {
        this->Color = color;
        this->Figure = figure;
    };
    void info() {
        cout << this->Color << " " << this->Figure << " Mouth" << endl;
    }
};

class Ears
{
public:
    string Color;
    string Figure;
    Ears(string color, string figure)
    {
        this->Color = color;
        this->Figure = figure;
    };
    void info() {
        cout << this->Color << " " << this->Figure << " Ears" << endl;
    }
};

class Hair
{
public:
    string Color;
    string Figure;
    Hair(string color, string figure)
    {
        this->Color = color;
        this->Figure = figure;
    };
    void info() {
        cout << this->Color << " " << this->Figure << " Hair" << endl;
    }
};


class Face
{
public:
    vector<Eyes> vi;
    vector<Nose> va;
    vector<Mouth>vh;
    vector<Ears> vc;
    vector<Hair> ve;
    void info() {
        int i;
        for (i = 0; i < vi.size(); ++i)  vi[i].info();
        for (i = 0; i < va.size(); ++i)  va[i].info();
        for (i = 0; i < vh.size(); ++i)  vh[i].info();
        for (i = 0; i < vc.size(); ++i)  vc[i].info();
        for (i = 0; i < ve.size(); ++i)  ve[i].info();
    }
};



class ConcreteBuilder
{
protected:
    Face* p;
public:
    ConcreteBuilder() : p(0) {}
    virtual ~ConcreteBuilder() {}
    virtual void createFace() {}
    virtual void buildEyes() {}
    virtual void buildNose() {}
    virtual void buildMouth() {}
    virtual void buildEars() {}
    virtual void buildHair() {}
    virtual Face* getFace() { return p; }
};


class UglyFaceBuilder : public ConcreteBuilder
{
public:
    void createFace() { p = new Face; }
    void buildEyes() { p->vi.push_back(Eyes("black", "ugly")); }
    void buildNose() { p->va.push_back(Nose("big", "ugly")); }
    void buildMouth() { p->vh.push_back(Mouth("horrible", "ugly")); }
    void buildEars() { p->vc.push_back(Ears("curves", "ugly")); }
};


class GoodFaceBuilder : public ConcreteBuilder
{
public:
    void createFace() { p = new Face; }
    void buildEyes() { p->vi.push_back(Eyes("white", "good")); }
    void buildNose() { p->va.push_back(Nose("broken", "good")); }
    void buildMouth() { p->vh.push_back(Mouth("wide", "good")); }
    void buildHair() { p->ve.push_back(Hair("white", "good")); }
};

class SmileFaceBuilder : public ConcreteBuilder
{
public:
    void createFace() { p = new Face; }
    void buildEyes() { p->vi.push_back(Eyes("blue", "smile")); }
    void buildNose() { p->va.push_back(Nose("strong", "smile")); }
    void buildMouth() { p->vh.push_back(Mouth("big", "smile")); }
    void buildEars() { p->vc.push_back(Ears("small", "smile")); }
    void buildHair() { p->ve.push_back(Hair("dark", "smile")); }
};


class Director
{
public:
    Face* createFace(ConcreteBuilder& builder)
    {
        builder.createFace();
        builder.buildEyes();
        builder.buildNose();
        builder.buildMouth();
        builder.buildEars();
        builder.buildHair();
        return(builder.getFace());
    }
};


int main()
{
    Director dir;
    UglyFaceBuilder ra_builder;
    GoodFaceBuilder ca_builder;
    SmileFaceBuilder da_builder;

    Face* ra = dir.createFace(ra_builder);
    Face* ca = dir.createFace(ca_builder);
    Face* da = dir.createFace(da_builder);
    cout << "Ugly Face:" << endl;
    ra->info();
    cout << "\nGood Face:" << endl;
    ca->info();
    cout << "\nSmile Face:" << endl;
    da->info();
    return 0;
}