#include <iostream>
#include <vector>

using namespace std;

class Node//klasa wezla
{
public:
    Node(string name)
    {
        this->name=name;
    }
    vector<Node*> children;//wektor ze wskaznikami pokazujacymi na dzieci tego wezla
    string name;//nazwa wezla
    int nestLevel;//poziom zagniezdzenia

    void newChildren(string name)//dodawanie dziecka dla podanego rodzica
    {
        Node* temp=new Node(name);//tworze nowy wskaznik do dynamiczneogo obiektu typu Node
        temp->nestLevel=nestLevel+1;//ten obiekt ma zagniezdzenie o 1 wieksze od rodzica
        children.push_back(temp);//wpisuje dziecko do wektora z dziecmi u rodzica
    }
};

void printTree(Node* node)//drukuj drzewo
{
    static bool firstexe;//do sprawdzenia czy to pierwsze wywolanie
    static int firstNodeNest;//do sprawdzenia pierwszego zagniezdzenia
    if(!firstexe){
        cout<<node->name<<endl;
        firstNodeNest=node->nestLevel;
        firstexe=true;
    }
    for(int i=0; i<node->children.size(); i++)//dla kazdego dziecka z wektora
    {
        for(int j=0; j<((node->children[i]->nestLevel)-firstNodeNest); j++)//zrob wciecie(zagniezdzenie) dla dziecka
        {
            cout<<"\t";
        }
        cout<<node->children[i]->name<<endl;//drukuj nazwe dziecka
        printTree(node->children[i]);//drukuj nizsze poziomy
    }
}

int main()
{
    Node root("root");//stworz root
    root.nestLevel=0;//dodaj zagniezdzenie
    root.newChildren("A");//dodaj dziecko do root
    root.children[0]->newChildren("AA");//dodaj dziecko do A
    root.children[0]->newChildren("AB");//dodaj dziecko do A
    root.children[0]->children[0]->newChildren("AAA");//dodaj dziecko do AA
    root.newChildren("B");//dodaj dziecko do root
    root.children[1]->newChildren("BA");//dodaj dziecko do B
    root.children[1]->newChildren("BB");//dodaj dziecko do B
    printTree(root.children[0]);//wyswietl drzewo od wybranego node'a

    return 0;
}
