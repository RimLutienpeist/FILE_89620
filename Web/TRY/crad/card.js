const cards = document.querySelectorAll('.card');
cards.forEach(card => {
    card.addEventListener('click', e => {
        card.classList.toggle('flipped');
    });

    const emailButton = card.querySelector('button');
    const originalButtonColor = emailButton.style.backgroundColor;

    emailButton.addEventListener('mouseover', e => {
        emailButton.style.backgroundColor = 'green';
    });

    emailButton.addEventListener('mouseout', e => {
        emailButton.style.backgroundColor = originalButtonColor;
    });

    const elements = card.querySelectorAll('img, h1, p, button');
    elements.forEach(element => {
        element.addEventListener('mouseover', e => {
            element.style.animation = 'pulse 1s infinite';
        });

        element.addEventListener('mouseout', e => {
            element.style.animation = '';
        });
    });
});

