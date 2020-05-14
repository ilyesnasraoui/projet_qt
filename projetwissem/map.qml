import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6
import QtLocation 5.14
import QtQuick.Controls 1.4

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
    }
    PositionSource{
        active: true
        onPositionChanged: {
            map.center=position.coordinate ;
        }
    }
    Map {
        id:map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.169019,8.701230)
        zoomLevel: 15

        Column{
            id:tools
            anchors.fill: parent
            anchors.margins: 5
            spacing: 3
            Rectangle{
                id: frame
                width: parent.width
                height:25
                border.color: grey
                border.width: 1
                TextInput{
                    id:lagitude
                    anchors.fill:parent
                    anchors.margins: 4
                    text: value1
                }

            }
            Rectangle{
                id: frame2
                width: parent.width
                height:25
                border.color: grey
                border.width: 1
                TextInput{
                    id: longitude
                    anchors.fill:parent
                    anchors.margins: 4
                    text: value2
                }

            }

            Button{
                id:search
                text: "search"
                onClicked: {
                    var latlong =  '-34.397,150.644'.split(',');
                    var latitude = parseFloat(latlong[0]);
                      var longitude = parseFloat(latlong[1]);
                    map.center=QtPositioning.coordinate(longitude,latitude);

                }
            }
        }

        MapQuickItem{
            id: marker
            coordinate :QtPositioning.coordinate(35.991418, 8.687954)
            sourceItem: Image {
                id: image
                source:  "map_marquer.png"
                width: 50
                height: 50
            }
            anchorPoint.x:image.width /2
            anchorPoint.y:image.height
        }
        MapItemView{
            model: routeModel
            delegate: Component{
                MapRoute{
                    route: routeData
                    line.color: "green"
                    line.width: 4
                }
            }
        }
    }
    GeocodeModel{
        plugin: map.plugin
        query: "53 Brandl St, Eight Mile Plains, Australia"
        onLocationsChanged: {
            if(count)
                marker.coordinate=get(0).coordinate;

        }
            Component.onCompleted: update()

    }
    RouteModel{
        id:routeModel
        plugin: map.plugin
        query:RouteQuery {id:routeQuery}
        Component.onCompleted: {
            routeQuery.addWaypoint(QtPositioning.coordinate(36.169019,8.701230));
            routeQuery.addWaypoint(QtPositioning.coordinate(35.991418, 8.687954));
            update();
        }
    }

}
