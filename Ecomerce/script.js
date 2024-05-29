const bar = document.getElementById('bar');
const nav = document.getElementById('navbar');
const close=document.getElementById('close');


if (bar) {
    bar.addEventListener('click', () => {
        nav.classList.add('active');
    });
}

if(close){
    close.addEventListener('click', ()=>{
       nav.classList.remove('active');
    })
}

let main=document.getElementById('MainImg');
let small=document.getElementsByClassName('small-img');
small[0].onclick=function(){
    main.src=small[0].src;
}
small[1].onclick=function(){
    main.src=small[1].src;
}
small[2].onclick=function(){
    main.src=small[2].src;
}
small[3].onclick=function(){
    main.src=small[3].src;
}
