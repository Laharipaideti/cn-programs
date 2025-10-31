import 'package:flutter/material.dart'; 
void main() { 
runApp(const MyApp()); 
} 
class MyApp extends StatelessWidget { 
const MyApp({super.key}); 
@override 
Widget build(BuildContext context) { 
return MaterialApp( 
title: 'Flutter Container Demo', 
theme: ThemeData( 
primarySwatch: Colors.blue, 
), 
home: const MyHomePage(), 
); 
} 
} 
class MyHomePage extends StatelessWidget { 
const MyHomePage({super.key}); 
@override 
Widget build(BuildContext context) { 
return Scaffold( 
appBar: AppBar( 
title: const Text('Container Widget Demo'), 
), 
body: Center( 
child: Container( 
width: 200, 
height: 150, 
decoration: BoxDecoration( 
color: Colors.teal, 
borderRadius: BorderRadius.circular(15), 
boxShadow: const [ 
BoxShadow( 
color: Colors.black26, 
blurRadius: 10, 
offset: Offset(0, 5), 
), 
], 
), 
alignment: Alignment.center, 
child: const Text( 
'Hello Container!', 
style: TextStyle( 
color: Colors.white, 
fontSize: 20, 
fontWeight: FontWeight.bold, 
), 
), 
), 
), 
); 
} 
}