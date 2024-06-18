var locations = {
    'location1': [14.836375, 120.278112],
    'location2': [14.835408068840959, 120.28149424942553]
};

var searchBar = document.querySelector('.search');

searchBar.addEventListener('keyup', function(e) {
    if (e.key === 'Enter') {
        searchLocation(e.target.value);
    }
});

function searchLocation(query) {
    if (locations[query]) {
        map.flyTo(locations[query], 18);
    }
}