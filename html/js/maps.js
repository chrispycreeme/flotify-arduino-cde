var map = L.map('map').setView([14.836375, 120.278112], 13);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

var customIcon = L.icon({
    iconUrl: 'img/location_on_48dp_FILL1_wght400_GRAD0_opsz48.png',
    iconSize:     [60, 60],
    iconAnchor:   [22, 94],
    popupAnchor:  [-3, -76]
});

var marker = L.marker([14.836375, 120.278112], {icon: customIcon}).addTo(map);
var marker2 = L.marker([9.776641697816485, 118.76523128023013], {icon: customIcon}).addTo(map);

marker.on('click', function(e) {
    map.flyTo(e.target.getLatLng(), 18);
});

marker2.on('click', function(e) {
    map.flyTo(e.target.getLatLng(), 18);
});