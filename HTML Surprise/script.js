const button = document.getElementById("surprise");
const pic = document.getElementsByClassName("pic");

const addPic = () => {
  if(pic[0].childNodes.length < 2) {
    const img = document.createElement("img");
    img.src = "ocelot1.jpg";
    img.alt = "Happy birthday ocelot";
    img.height = 150;
    img.width = 150;

    pic[0].appendChild(img);
  }
}

button.addEventListener("click", addPic);
