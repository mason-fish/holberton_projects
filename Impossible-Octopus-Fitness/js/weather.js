function get_weather(data) {
  report = document.getElementById('weather');
  report.innerHTML = data.current_weather;
}

function weather_button() {
  document.getElementById('weatherButton').addEventListener('click', function() {
    var script = document.createElement('script');
    script.src = "https://holberton-weather-api.herokuapp.com/weather.js?jsonp_callback=get_weather";
    document.head.appendChild(script);
    script.onload = function () {
      this.remove();
    };
  })
}
