import 'dart:math';

import 'package:flutter/material.dart';

void main() => runApp(MaterialApp(
      debugShowCheckedModeBanner: false,
      title: "Diceroller",
      home: Homepage(),
    ));

class Homepage extends StatefulWidget {
  const Homepage({super.key});

  @override
  State<Homepage> createState() => _HomepageState();
}

class _HomepageState extends State<Homepage> {
  int diceNumber = 1;

  changedice() {
    setState(() {
      diceNumber = Random().nextInt(6) + 1;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.red,
        title: Text("DiceRoller"),
        centerTitle: true,
      ),
      body: Column(
        children: [
          SizedBox(
            height: 30,
          ),
          Center(
            child: Image.asset(
              "assets/$diceNumber.png",
              height: 250,
              width: 250,
            ),
          ),
          MaterialButton(
            color: Colors.red,
            onPressed: changedice,
            child: Text(
              "Roll The Dice",
              style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.w500,
                color: Colors.white,
              ),
            ),
          ),
          SizedBox(
            height: 60,
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Text(
                "Current Dice Number is : ",
                style: TextStyle(
                  fontWeight: FontWeight.w500,
                ),
              ),
              Center(
                child: Image.asset(
                  "assets/$diceNumber.png",
                  height: 100,
                  width: 100,
                ),
              ),
            ],
          ),
          SizedBox(
            height: 60,
          ),
          const Text(
            "Copyright@sagarsharma2023",
            style: TextStyle(
              fontWeight: FontWeight.w300,
            ),
          ),
        ],
      ),
    );
  }
}
