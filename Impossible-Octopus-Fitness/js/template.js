
function template() {
  var theData = {name:"Shop Page", weekDay:"Wednesday"};

  var theTemplateScript = document.getElementById('header').innerHTML;
  var theTemplate = Handlebars.compile(theTemplateScript);
  var result = theTemplate(theData);

  document.getElementById('result').innerHTML = result;
  //document.body.appendChild(theTemplate(theData));
}
