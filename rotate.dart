// Program for ROTATE animation
import 'package:flutter/material.dart';
import 'dart:math';

void main() => runApp(RotateExample());

class RotateExample extends StatefulWidget {
  @override
  _RotateExampleState createState() => _RotateExampleState();
}

class _RotateExampleState extends State<RotateExample>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation<double> _rotateAnimation;

  @override
  void initState() {
    super.initState();
    _controller =
        AnimationController(vsync: this, duration: Duration(seconds: 2));
    _rotateAnimation =
        Tween<double>(begin: 0, end: 2 * pi).animate(_controller);
    _controller.repeat(); // Keeps rotating continuously
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text("Rotate Animation")),
        body: Center(
          child: RotationTransition(
            turns: _rotateAnimation,
            child: Container(
              width: 100,
              height: 100,
              color: Colors.red,
            ),
          ),
        ),
      ),
    );
  }
}