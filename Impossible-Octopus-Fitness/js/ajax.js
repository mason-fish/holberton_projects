//function for requesting a file through xmlhttprequest

function ajaxGet(url, onSuccess) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (xhttp.readyState==4) {
      onSuccess(xhttp.responseText);
    }
  }
  xhttp.open("GET", url, true);
  xhttp.send();
}
