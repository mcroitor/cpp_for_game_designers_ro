class Mos
{
public:
    Mos();
};

class MosVesel : public Mos
{
public:
    MosVesel();
};

int main()
{
    Mos *mos = new MosVesel;
}