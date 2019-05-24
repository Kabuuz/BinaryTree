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
    Node* parent;//wskaznik na rodzica
};

void newChildren(string name,Node* parent)//dodawanie dziecka dla podanego rodzica
{
    Node* temp=new Node(name);//tworze nowy wskaznik do dynamiczneogo obiektu typu Node
    temp->nestLevel=(parent->nestLevel)+1;//ten obiekt ma zagniezdzenie o 1 wieksze od rodzica
    temp->parent=parent;//przypisuje dziecku wskaznik do rodzica
    parent->children.push_back(temp);//wpisuje dziecko do wektora z dziecmi u rodzica
}

void printTree(Node* node)//drukuj drzewo
{
    for(int i=0; i<node->children.size(); i++)//dla kazdego dziecka z wektora
    {
        for(int j=0; j<node->children[i]->nestLevel; j++)//zrob wciecie(zagniezdzenie) dla dziecka
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
    newChildren("A",&root);//dodaj dziecko do root
    newChildren("AA",root.children[0]);//dodaj dziecko do A
    newChildren("AB",root.children[0]);//dodaj dziecko do A
    newChildren("AAA",root.children[0]->children[0]);//dodaj dziecko do AA
    newChildren("B",&root);//dodaj dziecko do root
    newChildren("BA",root.children[1]);//dodaj dziecko do B
    newChildren("BB",root.children[1]);//dodaj dziecko do B
    cout<<root.name<<endl;//wypisz nazwe roota
    printTree(&root);//wyswietl drzewo od roota

    return 0;
}
