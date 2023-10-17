import 'package:flutter/material.dart';

void main() => runApp(
      MaterialApp(
        debugShowCheckedModeBanner: false,
        title: "TodoApp",
        home: todoapp(),
      ),
    );

class todoapp extends StatefulWidget {
  const todoapp({super.key});

  @override
  State<todoapp> createState() => _todoappState();
}

class _todoappState extends State<todoapp> {
  String value = "sagar";
  var listtodo = [' '];

  addtodo(String item) {
    setState(() {
      listtodo.add(item);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.amber,
        title: Text(
          "To-Do App",
        ),
        centerTitle: true,
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          addtodo(value);
        },
        child: Icon(Icons.add),
        backgroundColor: Colors.amber,
      ),
      body: Column(
        children: <Widget>[
          Expanded(
            child: ListView.builder(
                itemCount: listtodo.length,
                itemBuilder: (context, index) {
                  return index == 0
                      ? Padding(
                          padding: const EdgeInsets.all(25),
                          child: TextField(
                            decoration: InputDecoration(
                                border: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(20),
                                ),
                                hintText: 'Add items'),
                            onChanged: (val) {
                              value = val;
                            },
                          ),
                        )
                      : ListTile(
                          title: Text(
                            '${listtodo[index]}',
                            style: TextStyle(fontWeight: FontWeight.w500),
                          ),
                          leading: Icon(Icons.upcoming),
                        );
                }),
          ),
        ],
      ),
    );
  }
}
