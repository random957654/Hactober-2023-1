import 'package:flutter/material.dart';

void main() {
  runApp(ScoreApp());
}

class ScoreApp extends StatelessWidget {
  const ScoreApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Score App',
      home: Scorehome(),
    );
  }
}

class Scorehome extends StatefulWidget {
  const Scorehome({super.key});

  @override
  State<Scorehome> createState() => _ScorehomeState();
}

class _ScorehomeState extends State<Scorehome> {
  int number = 0;
  void increaseNumber() {
    setState(() {
      number++;
    });
  }

  void decreaseNumber() {
    setState(() {
      number--;
    });
  }

  void resetNumber() {
    setState(() {
      number = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Score App'),
        centerTitle: true,
      ),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.reset_tv),
        onPressed: resetNumber,
      ),
      body: Column(
        children: [
          SizedBox(
            height: 30,
          ),
          Center(
              child: Text("Score is",
                  style: TextStyle(
                    color: Colors.green,
                    fontSize: 30,
                    fontWeight: FontWeight.w600,
                  ))),
          SizedBox(
            height: 30,
          ),
          Center(
              child: Text(number.toString(),
                  style: TextStyle(
                    color: Colors.green,
                    fontSize: 100,
                    fontWeight: FontWeight.w800,
                  ))),
          SizedBox(
            height: 30,
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              ElevatedButton(
                  onPressed: increaseNumber,
                  child: Text(
                    "Increase",
                    style: TextStyle(fontSize: 20, fontWeight: FontWeight.w500),
                  )),
              SizedBox(
                width: 25,
              ),
              ElevatedButton(
                  onPressed: decreaseNumber,
                  child: Text(
                    "Decrease",
                    style: TextStyle(fontSize: 20, fontWeight: FontWeight.w500),
                  )),
            ],
          ),
          SizedBox(
            height: 100,
          ),
          const Text("Copyright@learningflutter2023"),
        ],
      ),
    );
  }
}
