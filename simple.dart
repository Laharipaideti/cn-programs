void main() 
{ 
int myNumber=10; 
double myDouble=3.14; 
String myString= 'Hello World'; 
bool myBool=true; 
print('My number is:$myNumber'); 
print('My double is:$myDouble'); 
print('My string is:$myString'); 
print('My bool is:$myBool'); 
int result=myNumber+5; 
print('result of addition:$result'); 
if(myBool) { 
print('my bool is true'); 
} 
else 
print('my bool is false'); 
for(int i=0;i<5;i++) { 
print('Iteration $i'); 
} 
List<int> numbers=[1,2,3,4,5]; 
print('first element of the list:${numbers[0]}'); 
print('length of the lists:${numbers.length}'); 
}