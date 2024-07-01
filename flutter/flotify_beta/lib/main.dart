import 'package:flutter/material.dart';

void main() {
  runApp(MainApp());
}

class MainApp extends StatefulWidget {
  MainApp({Key? key}) : super(key: key);

  @override
  _MainAppState createState() => _MainAppState();
}

class _MainAppState extends State<MainApp> {
  bool isFirstButtonExpanded = false;
  bool isSecondButtonExpanded = false;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Stack(
          children: [
            Container(
              decoration: BoxDecoration(
                image: DecorationImage(
                  image: AssetImage("assets/bg_photo_B.png"),
                  fit: BoxFit.cover,
                  alignment: Alignment.center,
                ),
              ),
            ),
            Container(
              color: Color(0xFF1B1F3B).withOpacity(0.93),
            ),
            Column(
              children: [
                Expanded(
                  child: Center(
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Container(
                          margin: EdgeInsets.only(bottom: 50),
                          child: Column(
                            children: [
                              Image(
                                image: AssetImage(
                                    "assets/floatify-logo-transparent-white.png"),
                                width: 230,
                                height: 75,
                              ),
                              Padding(
                                padding: EdgeInsets.only(top: 0),
                                child: Text(
                                  "Save Lives, Ligtas ang may Alam!",
                                  style: TextStyle(
                                    fontFamily: 'Inter',
                                    fontStyle: FontStyle.italic,
                                    color: Color(0xFFDFE2E1),
                                    fontSize: 12,
                                  ),
                                ),
                              ),
                            ],
                          ),
                        ),
                        SizedBox(height: 30),
                        Text(
                          "Select a Communication Protocol",
                          style: TextStyle(
                            fontFamily: 'Inter',
                            fontStyle: FontStyle.italic,
                            color: Color(0xFFDFE2E1),
                            fontSize: 12,
                          ),
                        ),
                        SizedBox(height: 20),
                        SizedBox(
                          width: 260,
                          height: isFirstButtonExpanded
                              ? 120
                              : 60, // Adjust height based on isExpanded
                          child: ElevatedButton(
                            onPressed: () {},
                            style: ElevatedButton.styleFrom(
                              backgroundColor: Color(0xFF202235),
                              shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(15),
                              ),
                            ),
                            child: Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Row(
                                      children: [
                                        Container(
                                          padding: EdgeInsets.all(5),
                                          decoration: BoxDecoration(
                                            color: Color(0xFF262A4C),
                                            borderRadius:
                                                BorderRadius.circular(50),
                                          ),
                                          child: Icon(
                                            Icons.bluetooth,
                                            color: Color(0xFF00F0B5),
                                            size: 21,
                                          ),
                                        ),
                                        SizedBox(width: 8),
                                        Column(
                                          mainAxisSize: MainAxisSize.min,
                                          crossAxisAlignment:
                                              CrossAxisAlignment.start,
                                          children: <Widget>[
                                            Text(
                                              "Bluetooth Mode",
                                              style: TextStyle(
                                                fontFamily: 'Inter',
                                                color: Color(0xFFDFE2E1),
                                                fontSize: 13,
                                              ),
                                            ),
                                            Text(
                                              "Offline Mode",
                                              style: TextStyle(
                                                  fontFamily: 'Inter',
                                                  color: Color(0xFF86849B),
                                                  fontSize: 9,
                                                  fontStyle: FontStyle.italic),
                                            ),
                                          ],
                                        ),
                                      ],
                                    ),
                                    IconButton(
                                      icon: Icon(
                                          Icons.arrow_drop_down_circle_outlined,
                                          color: Color(0xFF262A4C)),
                                      onPressed: () {
                                        setState(() {
                                          isFirstButtonExpanded =
                                              !isFirstButtonExpanded;
                                        });
                                      },
                                    ),
                                  ],
                                ),
                                if (isFirstButtonExpanded) // Conditionally display additional text
                                  Padding(
                                    padding: EdgeInsets.only(top: 8),
                                    child: Text(
                                      "Additional Information",
                                      style: TextStyle(
                                        color: Color(0xFFDFE2E1),
                                        fontSize: 11,
                                      ),
                                    ),
                                  ),
                              ],
                            ),
                          ),
                        ),
                        SizedBox(height: 12),
                        SizedBox(
                          width: 260,
                          height: isSecondButtonExpanded
                              ? 120
                              : 60, // Adjust height based on isExpanded
                          child: ElevatedButton(
                            onPressed: () {},
                            style: ElevatedButton.styleFrom(
                              backgroundColor: Color(0xFF202235),
                              shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(15),
                              ),
                            ),
                            child: Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Row(
                                      children: [
                                        Container(
                                          padding: EdgeInsets.all(5),
                                          decoration: BoxDecoration(
                                            color: Color(0xFF262A4C),
                                            borderRadius:
                                                BorderRadius.circular(50),
                                          ),
                                          child: Icon(
                                            Icons.bluetooth,
                                            color: Color(0xFF00F0B5),
                                            size: 21,
                                          ),
                                        ),
                                        SizedBox(width: 8),
                                        Column(
                                          mainAxisSize: MainAxisSize.min,
                                          crossAxisAlignment:
                                              CrossAxisAlignment.start,
                                          children: <Widget>[
                                            Text(
                                              "Bluetooth Mode",
                                              style: TextStyle(
                                                fontFamily: 'Inter',
                                                color: Color(0xFFDFE2E1),
                                                fontSize: 13,
                                              ),
                                            ),
                                            Text(
                                              "Offline Mode",
                                              style: TextStyle(
                                                  fontFamily: 'Inter',
                                                  color: Color(0xFF86849B),
                                                  fontSize: 9,
                                                  fontStyle: FontStyle.italic),
                                            ),
                                          ],
                                        ),
                                      ],
                                    ),
                                    IconButton(
                                      icon: Icon(
                                          Icons.arrow_drop_down_circle_outlined,
                                          color: Color(0xFF262A4C)),
                                      onPressed: () {
                                        setState(() {
                                          isSecondButtonExpanded =
                                              !isSecondButtonExpanded;
                                        });
                                      },
                                    ),
                                  ],
                                ),
                                if (isSecondButtonExpanded) // Conditionally display additional text
                                  Padding(
                                    padding: EdgeInsets.only(top: 8),
                                    child: Text(
                                      "Additional Information",
                                      style: TextStyle(
                                        color: Color(0xFFDFE2E1),
                                        fontSize: 11,
                                      ),
                                    ),
                                  ),
                              ],
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
                Opacity(
                  opacity: 0.07,
                  child: Container(
                    padding: EdgeInsets.all(20),
                    color: Colors.transparent,
                    child: Column(
                      children: [
                        Text(
                          "Flotify is a Project of:",
                          style: TextStyle(
                            fontFamily: 'Inter',
                            color: Color(0xFFDFE2E1),
                            fontSize: 13,
                            fontStyle: FontStyle.italic,
                          ),
                        ),
                        SizedBox(height: 15),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Flexible(
                              child: ClipOval(
                                child: Image.asset(
                                  "assets/apluslogo.png",
                                  width: 50,
                                  height: 50,
                                  fit: BoxFit.cover,
                                ),
                              ),
                            ),
                            SizedBox(width: 10),
                            Flexible(
                              child: Image(
                                image: AssetImage("assets/STElogo.png"),
                                width: 50,
                                height: 50,
                              ),
                            ),
                            SizedBox(width: 10),
                            Flexible(
                              child: Image(
                                image: AssetImage("assets/CityLogo.png"),
                                width: 50,
                                height: 50,
                              ),
                            ),
                          ],
                        ),
                      ],
                    ),
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
} // Class Main
