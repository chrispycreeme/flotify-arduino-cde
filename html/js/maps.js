var map = L.map('map').setView([14.836375, 120.278112], 13);

L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

var legend = L.control({ position: 'bottomright' });

legend.onAdd = function (map) {
    var div = L.DomUtil.create('div', 'legend');

    div.innerHTML += '<h4>Legend</h4>';
    div.innerHTML += '<i style="background: url(assets/icons/location_on_48dp_FILL1_wght400_GRAD0_opsz48.png) no-repeat center; width: 10px; height: 10px; display: inline-block;"></i> Station Location<br>';
    div.innerHTML += '<i style="background: url(assets/icons/shield_with_house_48dp_FILL1_wght300_GRAD200_opsz20.png) no-repeat center; width: 10px; height: 10px; display: inline-block;"></i> Evacuation Location<br>';

    return div;
};

legend.addTo(map);

var stationLocation = L.icon({
    iconUrl: 'assets/icons/location_on_48dp_FILL1_wght400_GRAD0_opsz48.png',
    iconSize: [40, 40],
});

var marker = L.marker([14.836375, 120.278112], { icon: stationLocation }).addTo(map);
var marker2 = L.marker([9.776641697816485, 118.76523128023013], { icon: stationLocation }).addTo(map);

marker.on('click', function (e) {
    map.flyTo(e.target.getLatLng(), 18);
});

marker2.on('click', function (e) {
    map.flyTo(e.target.getLatLng(), 18);
});

var evacuationLocation = L.icon({
    iconUrl: 'assets/icons/shield_with_house_48dp_FILL1_wght300_GRAD200_opsz20.png',
    iconSize: [40, 40],
});

var evacuation1 = L.marker([14.849261885135427, 120.31312129680448], { icon: evacuationLocation }).addTo(map);

evacuation1.on('click', function (e) {
    map.flyTo(e.target.getLatLng(), 18);
});

