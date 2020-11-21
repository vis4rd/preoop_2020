#include "MyDir.h"

void initDir(MyDir &target, std::string name)
{        
    target.parent = NULL;
    target.children = NULL;
    target.childCount = 0;
    target.name = name;
}

void printDir(MyDir target, int depth)
{
    for(int i=0; i<depth-1; i++)
        std::cout<<"   ";
    if(depth!=0)
        std::cout<<"|__";
    std::cout<< target.name;

    if( target.children )
    {
        std::cout<<std::endl;
        for(int i = 0; i<target.childCount; i++)
        {
            printDir(*target.children[i], depth+1);
        }
    }
    else
        std::cout << std::endl;
}

MyDir *addDir(MyDir &parent, std::string childName)
{  	
    int nameCheck = isNameOK(childName);
    if(nameCheck == 1)
    {
        std::cout << "Za dluga nazwa: " << childName << std::endl;
        return NULL;
    }
    else if (nameCheck == -1)
    {
        std::cout << "Za krotka nazwa" << std::endl;
        return NULL;
    }

    MyDir *child = new MyDir;
    initDir(*child, childName); 

    MyDir **temp = parent.children;
    parent.children = new MyDir*[parent.childCount+1];
    for(int i=0; i<parent.childCount; i++)
        parent.children[i] = temp[i];
    
    delete[] temp;
    parent.children[parent.childCount] = child;
    parent.childCount++;

    child->parent = &parent;

    return child;
}

MyDir *addDir(MyDir &parent, MyDir &child)
{
    MyDir **temp = parent.children;
    parent.children = new MyDir*[parent.childCount+1];
    for(int i=0; i<parent.childCount; i++)
        parent.children[i] = temp[i];
    
    delete[] temp;
    parent.children[parent.childCount] = &child;
    parent.childCount++;

    child.parent = &parent;

    return &child;
}

void clearDir(MyDir *target)
{
    if(target->childCount == 0)//nie posiada podfolderow
    {
        if(target->parent != NULL)
            target->parent->childCount -= 1;

        //std::cout<<__func__<<": "<<target->name<<" - parent: "<<target->parent->name<<std::endl;
        //std::cout<<__func__<<": "<<target->name<<" - no children"<<std::endl;
        if(target->children != NULL)
            delete[] target->children;
        //std::string temp = target->name;
        delete target;
        //std::cout<<__func__<<": "<<temp<<" - self-destruction complete\n"<<std::endl;
    }
    else//posiada podfoldery
    {
        /*if(target->parent != NULL)
            std::cout<<__func__<<": "<<target->name<<" - parent: "<<target->parent->name<<std::endl;
        else
            std::cout<<__func__<<": "<<target->name<<" - no parent"<<std::endl;
        */

        int childCount = target->childCount;//uzywamy zmiennej zastepczej, poniewaz 
                //... "target->parent->childCount -= 1" zmienia nam liczbe iteracji 
                //... ponizszej petli for.
            
        for(int i=0; i<childCount; i++)
        {
            //std::cout<<__func__<<": "<<target->name<<" - child found: "<<target->children[i]->name<<std::endl;
            clearDir(target->children[i]);
        }
        //std::cout<<__func__<<": "<<target->name<<" - children deleted!"<<std::endl;
        target->childCount = 0;

        if(target->children != NULL)
            delete[] target->children;
        //std::cout<<__func__<<": "<<target->name<<" - container freed"<<std::endl;

        if(target->parent != NULL)
            target->parent->childCount -= 1;

        //std::string temp = target->name;
        if(target->name != "Jan" && target->name != "root"){
            //bierzemy pod uwage, ze foldery Jan, root nie sa wskaznikami
            //... na zaalokowany obszar pamieci (nie wiem dlaczego),
            //... tylko zwyklymi statycznymi obiektami
            delete target;
        }
        //std::cout<<__func__<<": "<<temp<<" - self-destruction complete\n"<<std::endl;
    }
}

int tabLength(MyDir **target)
{
    MyDir **iter = target;
    if(iter == NULL)
    {
        //std::cout<<__func__<<": target == NULL"<<std::endl;
        return 0;
    }
    else
    {
        while(*iter!=NULL)
            iter++;
        //std::cout<<__func__<<": "<<iter - target<<std::endl;
        return iter-target;
    }
}

int isNameOK(std::string target)
{
    //std::cout<<__func__<<": "<<target<<" - "<<target.length()<<std::endl;
    if(target.length() < 1)
        return -1;
    else if (target.length() > 10)
        return 1;
    
    return 0;
}