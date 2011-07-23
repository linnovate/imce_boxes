Drupal.behaviors.imceBoxes = function (context) {
  $('#imce-browser-ph').click(function(){
    window.open(Drupal.settings.basePath+'imce?app=myApp|url%40edit-imce-image-path', '', 'width=760,height=560, resizable=1', '', '', '', 'ff');
  });
}
