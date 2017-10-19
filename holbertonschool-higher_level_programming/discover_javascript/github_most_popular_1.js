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
    res.on('data', function(d) {
	process.stdout.write(d);
    });
});
req.end();

req.on('error', function(e) {
    console.error(e);
});
