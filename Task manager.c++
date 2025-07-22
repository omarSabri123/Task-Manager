#include <iostream>
using namespace std;
static int num = 1 ;
class Task {
    private:
       string TaskName ;
       string  Data ;
       string condition ;
    public:
       Task (){
       cout<<"Task : "<<num<<endl;
       cout<<"Enter the Task name : ";
       cin>>TaskName ;

       cout<<"Enter the Mission history : ";
       cin>>Data ;

       cout<<"Enter the condition : ";
       cin>>condition;
       
       num ++;
       cout<<endl;
       } 
    // The print function is responsible for printing information about any task.
    void print (Task ob[], int size){
      for(int x = 0 ; x < size ; x++){
         cout<<"Task : "<<x + 1<<endl;
         cout<<"Task name : "<<ob[x].TaskName<<endl;
         cout<<"Data : "<<ob[x].Data<<endl;
         cout<<"condition : "<<ob[x].condition<<endl;
      }
       
    }
    // Delete function through which any task can be deleted
    void Delete(Task ob [] , int& size){
        cout<<"Deletion location "<<endl;
        string name ;
        string confirmation ;
        do{
            cout<<"Enter the name of the task you want to delete  :  ";
            cin>>name ;
            if(size == 0){
                cout<<"Sorry, there are no tasks "<<endl;
                break ;
            }
            bool Verification = false ;
            int index = 0 ;
            for(int x = 0 ; x < size ; x++){
                if(name == ob[x].TaskName){
                    index = x ;
                    Verification = true ;
                    break ;
                }
            }
            if(Verification){
                for(int x = index ; x < size - 1 ; x++){
                    ob[x] = ob[x + 1];
                }
                size -- ;
                cout<<"The task was successfully deleted "<<endl;
                cout<<"Tasks after deletion "<<endl;
                for(int x = 0 ; x < size ; x++){
                   cout<<"Task name : "<<ob[x].TaskName<<endl;
                   cout<<"Data : "<<ob[x].Data<<endl;
                   cout<<"condition : "<<ob[x].condition<<endl;
                }
            }
            else 
            cout<<"Sorry, the mission name you wrote does not exist. "<<endl;
            cout<<"Do you want to accomplish another mission? Answer yes or no : ";
            cin>>confirmation;
        }while(confirmation == "yes");
    }
    // Edit function through which you can modify the information of any task
    void Edit(Task ob [] , int size){
        cout<<"Place of modification "<<endl;
        string name ;
        string confirmation ;
        do{
            if(size == 0){
                cout<<"Sorry, there are no tasks "<<endl;
                break ;
            }
            
            cout<<"Enter the name of the task you want to modify  :  ";
            cin>>name ;
            bool Verification = false;
            for(int x = 0 ; x < size ; x ++){
                if(name == ob[x].TaskName){
                    cout<<"Task name : ";
                    cin>>ob[x].TaskName ;
                    cout<<"Data : ";
                    cin>>ob[x].Data ;
                    cout<<"condition : ";
                    cin>>ob[x].condition ;
                    Verification = true ;
                }
            }
            if(!Verification){
               cout<<"Sorry, the mission name you wrote does not exist. "<<endl; 
            }
            cout<<"Tasks after modification "<<endl;
            for(int x = 0 ; x < size ; x++){
            cout<<"Task name : "<<ob[x].TaskName<<endl;
            cout<<"Data : "<<ob[x].Data<<endl;
            cout<<"condition : "<<ob[x].condition<<endl;
            }
            cout<<"Do you want to accomplish another mission? Answer yes or no : ";
            cin>>confirmation;
        }while(confirmation == "yes");
    }
    // SearchForStatus function can be used to search for the status of any task.
    void SearchForStatus(Task ob [] , int size){
        cout<<"Search for status "<<endl;
        string condition ;
        string confirmation ;
        do{
            cout<<"What is the status you want to search for? : ";
            cin>>condition;
            if(size == 0){
                cout<<"Sorry, there are no tasks "<<endl;
                break ;
            }
            bool Verification = false ;
            for(int x = 0 ; x < size ; x++){
                if(condition == ob[x].condition){
                   cout<<"Task name : "<<ob[x].TaskName<<endl;
                   cout<<"Data : "<<ob[x].Data<<endl;
                   cout<<"condition : "<<ob[x].condition<<endl;
                   Verification = true ;
                }
            }
            if(!Verification){
                cout<<"Sorry, there are no tasks in this case "<<endl;
            }
            cout<<"Do you want to accomplish another mission? Answer yes or no : ";
            cin>>confirmation;
        }while(confirmation == "yes");
    }
    //NumberOfTasks function can be used to determine the number of instances of any task.
    void NumberOfTasks(Task ob [] , int size){
        cout<<"Number of tasks according to the status "<<endl;
        string condition ;
        int num = 0 ;
        bool Verification = false ;
        cout<<"Enter the status for which you want the number of tasks : ";
        cin>>condition;
        for(int x = 0 ; x < size ; x++){
            if(condition == ob[x].condition){
                num ++ ;
                Verification = true ;
            }
        }
        if(Verification){
            cout<<"Number of tasks   "<<condition<<" : "<<num<<endl;
        }
        else 
        cout<<"There are no tasks in this case "<<endl;
    }
};
int main() {
    int size , num;
    cout<<"Enter the number of tasks : ";
    cin>>size ;
    Task* ob1 = new Task[size];
    do{
       string num1 = "Print data";
       string num2 = "Delete a task";
       string num3 = "Modifying tasks";
       string num4 = "Search for task status";
       string num5 = "Number of tasks";
       string num6 = "Run the complete program";

       cout<<"number 1 : "<<num1<<endl;
       cout<<"number 2 : "<<num2<<endl;
       cout<<"number 3 : "<<num3<<endl;
       cout<<"number 4 : "<<num4<<endl;
       cout<<"number 5 : "<<num5<<endl;
       cout<<"number 6 : "<<num6<<endl;

       cout<<"Enter a number according to the options to do what you want : ";
       cin>>num;
       
       switch(num){
        case 1 :
        ob1[0].print(ob1 , size);
        break;

        case 2 :
        ob1[0].Delete(ob1 , size);
        break;

        case 3 :
        ob1[0].Edit(ob1 , size);
        break;

        case 4 :
        ob1[0].SearchForStatus(ob1 , size);
        break;

        case 5 :
        ob1[0].NumberOfTasks(ob1 , size);
        break;
        case 6 :
        ob1[0].print(ob1 , size);
        cout<<endl;
        ob1[0].Delete(ob1 , size);
        cout<<endl;
        ob1[0].Edit(ob1 , size);
        cout<<endl;
        ob1[0].SearchForStatus(ob1 , size);
        cout<<endl;
        ob1[0].NumberOfTasks(ob1 , size);
        break;
        
        default :
        cout<<"Sorry, this option is not available ";
       }


    }while(num != 0);

    delete [] ob1 ;
    return 0;
}
