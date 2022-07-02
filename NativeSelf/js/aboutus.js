// Toggle NAV-MENU
const toggleMenu = (toggleId, navId) => {
    const toggle_btn = document.getElementById(toggleId),
    nav = document.getElementById(navId)

    if(toggle_btn && nav) {
        toggle_btn.addEventListener('click', () => {
            nav.classList.toggle('show')
        })
    }
}
toggleMenu('menu_toggle_btn', 'nav__menu');

// CONTAINER's
gsap.from('.left_container', {
    delay:0,
    duration:0,
    top:"100%",
    ease:"expo.inOut"
});

gsap.from('.right_container', {
    delay:0,
    duration:0,
    bottom:"100%",
    ease:"expo.inOut"
});
// LOGO
gsap.from('.logo', {
    opacity:0,
    delay:0,
    duration:0,
    y:-20,
    ease:"expo.inOut"
});
// NAV-ITEM
gsap.from('.nav__item', {
    opacity:0,
    delay:0,
    duration:0,
    y:25,
    ease:"expo.Out",
    stagger:.2
});


// SOCIAL-ITEM
gsap.from('.social_item', {
    opacity:0,
    delay:0,
    duration:0,
    x:-25,
    ease:"expo.Out",
    stagger:.2
});


// PRODUCT-TTTLE
gsap.from('.product_title', {
    opacity:0,
    delay:0,
    duration:0,
    y:100,
    ease:"expo.inOut",
});
// PRODUCT-TYPE
gsap.from('.product_type', {
    opacity:0,
    delay:0,
    duration:0,
    y:100,
    ease:"expo.inOut",
});

// OVERLAY
gsap.to('.first', {
    delay:0,
    duration:0,
    top:"-100%",
    ease:"expo.inOut"
});
gsap.to('.second', {
    delay:0,
    duration:0,
    top:"-100%",
    ease:"expo.inOut"
});
gsap.to('.third', {
    delay:0,
    duration:0,
    top:"-100%",
    ease:"expo.inOut"
});
