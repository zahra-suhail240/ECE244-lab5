

//
//  BST.cpp
//  Lab 5 Search Through A Database
//
//  Created by Author Name, Date
#include "BST.h"

#include "Employee.h"

BST::BST(string order_) {
  root = NULL;
  order = order_;
}

BST::~BST(){
 delete root;
}

void insert_Helper (Employee* current, Employee* newEmployee, string order){ //like lec 26 the insert helper function
    if(order == "ID"){
        //checking left of subtree
        if(newEmployee->getID() < current ->getID()){
            if(current->getLeft()==NULL){
                current->setLeft(newEmployee);
            }
            else{
                insert_Helper(current->getLeft(), newEmployee, order);
            }
        }
        //checking right subtree
        if(newEmployee->getID() > current ->getID()){
            if(current->getRight()==NULL){
                current->setRight(newEmployee);
            }
            else{
                insert_Helper(current->getRight(), newEmployee, order);
            }
        }
    }
    else if(order == "name"){
        //left subtree
        if(newEmployee->getName() < current ->getName()){
            if(current->getLeft()==NULL){
                current->setLeft(newEmployee);
            }
            else{
                insert_Helper(current->getLeft(), newEmployee, order);
            }
        }
        //right subtree
        if(newEmployee->getName() > current ->getName()){
            if(current->getRight()==NULL){
                current->setRight(newEmployee);
            }
            else{
                insert_Helper(current->getRight(), newEmployee, order);
            }
        }
    }
    else if(order == "age"){
        //left subtree and check if identical age
        if(newEmployee->getAge() <= current->getAge()){
            if(current->getLeft()==NULL){
                current->setLeft(newEmployee);
            }
            else{
                insert_Helper(current->getLeft(), newEmployee, order);
            }
        }
        if(newEmployee->getAge() > current->getAge()){
            if(current->getRight()==NULL){
                current->setRight(newEmployee);
            }
            else{
                 insert_Helper(current->getRight(), newEmployee, order);
            
            }
        }
    }
}
void BST::insert(Employee* newEmployee){
// newEmployee is a pointer to a dynamically allocated Employee. Insert it
// according to the value of "order" of the binary search tree.

 if(root==NULL){
    root = newEmployee;
 }
 else{
    insert_Helper(root, newEmployee, order);
 }


}




void BST::printInOrder(){ //no need rihgt???
// print the Employees in the tree according its order
// Doesn't print anything if nothing is found

}


Employee* searchID_Helper(Employee* current, int ID){ //implement like the lec 26 bst search node

    if(current== NULL){
        return current;
    }
    if(current->getID()== ID){
        return current;
    }
    //check left subtree
    if(ID < current ->getID()){
        return searchID_Helper(current->getLeft(),ID);
    }
    //check right subtree
    if(ID > current->getID()){
        return searchID_Helper(current->getRight(),ID);
    }
    
}

Employee* BST:: searchID(int ID){
// search for an employee with a particular ID
// Prints "<ID> ID does not exist" if ID doesn't exist

return searchID_Helper(root,ID);

}

void searchAgeRange_Helper(Employee* current, double lowAge, double highAge){
    if(current == NULL){
        return;
    }
    
    //check left as it has the least age val

    /* if(current->getAge() < highAge){
         searchAgeRange_Helper(current->getRight(), lowAge, highAge);
    }
   */

     if(current->getAge() >= lowAge){
        searchAgeRange_Helper(current->getLeft(), lowAge, highAge);
    }

    if(current->getAge() >= lowAge){
        if(current->getAge() <= highAge){
            current->print();
        }
    }
    

    //check right
     if(current->getAge() < highAge){
         searchAgeRange_Helper(current->getRight(), lowAge, highAge);
    }
   
    
   
}
void BST::searchAgeRange(double lowAge, double highAge){
// search for employees within the age range
// Doesn't print anything if nothing is found

    searchAgeRange_Helper(root, lowAge, highAge);

}

void autocomplete_Helper(Employee* current, string prefix){
    if(current == NULL){
        return;
    }
    //check order of alphaabetic order (left sub tree)
    autocomplete_Helper(current->getLeft(), prefix);

    //to check use the .compare of the substring .compare(index0, size of word, string of the word prefix)
    if(current->getName().compare(0, prefix.length(), prefix)==0){//check if it sarts from other sides str.compare(pos,number of charac to comp, str2)
        current->print();
    }

    autocomplete_Helper(current->getRight(), prefix);

    
}
void BST::autocomplete(string prefix){
// Search for employees with names having the same prefix in the firstName +
// secondName If available, it prints them in order of their names in
// alphabetical order
// Doesn't print anything if nothing is found

autocomplete_Helper(root, prefix);

}



