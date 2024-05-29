const questions_list = [
    {
        questions: " In what year did the Great October Socialist Revolution take place?",
        answers: [
            { text: "1917", correct: true },
            { text: "1923", correct: false },
            { text: "1914", correct: false },
            { text: "1920", correct: false },
        ]
    },
    {
        questions: "What is the largest lake in the world?",
        answers: [
            { text: "Caspian Sea", correct: false },
            { text: "Baikal", correct: true },
            { text: "Lake Superior", correct: false },
            { text: "Ontario", correct: false },
        ]
    },
    {
        questions: " Which planet in the solar system is known as the “Red Planet”?",
        answers: [
            { text: "Venus", correct: false },
            { text: "Earth", correct: false },
            { text: "Mars", correct: true },
            { text: "Jupiter", correct: false },
        ]
    },
    {
        questions: "Who wrote the novel “War and Peace”?",
        answers: [
            { text: "Anton Chekhov", correct: false },
            { text: "Fyodor Dostoevsky", correct: false },
            { text: "Leo Tolstoy", correct: true },
            { text: "Ivan Turgenev", correct: false },
        ]
    }
];

const question = document.getElementById('question');
const answer_btn = document.getElementById('answer');
const next_btn = document.getElementById('next');
let currentQuestionIndex = 0;
score = 0;


function start() {
    currentQuestionIndex = 0;
    score = 0;
    next_btn.innerHTML = "Next";
    showQuestion();
}


function showQuestion() {
    resetState();
    let currentQuestion = questions_list[currentQuestionIndex];
    let questionNO = currentQuestionIndex + 1;
    question.innerHTML = questionNO + ". " + currentQuestion.questions;
    currentQuestion.answers.forEach(answers => {
        const button = document.createElement("button");
        button.innerHTML = answers.text;
        button.classList.add("btn");
        answer_btn.appendChild(button);
        if (answers.correct) {
            button.dataset.correct = answers.correct;
        }
        button.addEventListener("click", selectAnswer);
    });
}


function resetState() {
    next_btn.style.display = "none";
    while (answer_btn.firstChild) {
        answer_btn.removeChild(answer_btn.firstChild);
    }
}


function selectAnswer(e) {
    const selectbutton = e.target;
    const iscorrect = selectbutton.dataset.correct === "true";
    if (iscorrect) {
        selectbutton.classList.add("correct")
        score++;
    } else {
        selectbutton.classList.add("incorrect");
    }

    Array.from(answer_btn.children).forEach(button => {
        if (button.dataset.correct === "true") {
            button.classList.add("correct");
        }
        button.disabled = true;
    });
    next_btn.style.display = "block";
}


function showscore() {
    resetState();
    question.innerHTML = `Your score is ${score} out of ${questions_list.length}`;
    next_btn.innerHTML = "Play Again";
    next_btn.style.display = "block";
}


function handleNext_btn() {
    currentQuestionIndex++;

    if (currentQuestionIndex < questions_list.length) {
        showQuestion();
    }
    else {
        showscore();
    }
}

next_btn.addEventListener("click", () => {
    if (currentQuestionIndex < questions_list.length) {
        handleNext_btn();
    }
    else {
        start();
    }
});

start();



