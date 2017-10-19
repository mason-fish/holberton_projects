const https = require('https');

var options = {
    hostname: 'api.github.com',
    path: '/search/repositories?q=language:javascript&sort=stars&order=desc',
    headers: {
	'User-Agent': 'Holberton_School',
	'Authorization': 'token 1b97b1e74f551c675ad4bd92b6c327bd0fe2253d'
    }
};

var req = https.request(options, function(res) {
    streamToString(res, function(jsonString) {
	console.log(typeof jsonString);
	console.log(jsonString);
    });
});

req.end();

req.on('error', function(e) {
    console.error(e);
});

function streamToString(stream, cb) {
    const chunks = [];
    stream.on('data', function(chunk) {
	chunks.push(chunk);
    });
    stream.on('end', function() {
	cb(chunks.join(''));
    });
}
