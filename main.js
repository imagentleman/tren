function activateCard(e) {
  e.currentTarget.classList.add("active");
}

function deactivateCard(e) {
  e.preventDefault();
  var card = document.querySelector(".card.active");

  if (card) {
    card.classList.remove("active");
  }
}

document.addEventListener('keyup', function(e) {
  if (e.keyCode === 27) {
    deactivateCard(e);
  }
})
