let redplayer = "R";
let yellowplayer = "Y";
let current = redplayer;
let currentcolumn;
let row = 6;
let column = 7;
var board;
let gameover = false;

window.onload = function () {
    setgame();
}
function setgame() {
    board = [];
    currentcolumn = [5, 5, 5, 5, 5, 5, 5];
    for (let r = 0; r < row; r++) {
        let rows = [];
        for (let c = 0; c < column; c++) {
            rows.push(' ');
            let tile = document.createElement('div');
            tile.id = r.toString() + "-" + c.toString();
            tile.classList.add("tile");
            tile.addEventListener("click", setPiece);
            document.getElementById("board").append(tile)
        }
        board.push(rows);
    }
}

function setPiece() {
    if (gameover) {
        return;
    }
    let coords = this.id.split("-");

    let c = parseInt(coords[1]);
    r = currentcolumn[c];
    board[r][c] = current;

    let tile = document.getElementById(r.toString() + "-" + c.toString());

    if (current == redplayer) {
        tile.classList.add("red-piece");
        current = yellowplayer;
    }
    else {
        tile.classList.add("yellow-piece");
        current = redplayer;
    }
    r -= 1;
    currentcolumn[c] = r;
    checkwinner();
}
function checkwinner() {
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < column - 3; c++) {
            if (board[r][c] != ' ') {
                if (board[r][c] == board[r][c + 1] && board[r][c + 1] == board[r][c + 2] && board[r][c + 2] == board[r][c + 3]) {
                    setwinner(r, c);
                    return;
                }
            }
        }
    }

    for (let c = 0; c < column; c++) {
        for (let r = 0; r < row - 3; r++) {
            if (board[r][c] != ' ') {
                if (board[r][c] == board[r + 1][c] && board[r + 1][c] == board[r + 2][c] && board[r + 2][c] == board[r + 3][c]) {
                    setwinner(r, c);
                    return;
                }
            }


        }
    }

    for (let r = 0; r < row - 3; r++) {
        for (let c = 0; c < column - 3; c++) {
            if (board[r][c] != ' ') {
                if (board[r][c] == board[r + 1][c + 1] && board[r + 1][c + 1] == board[r + 2][c + 2] && board[r + 2][c + 2] == board[r + 3][c + 3]) {
                    setwinner(r, c);
                    return;
                }

            }

        }
    }

    for (let r = 3; r < row; r++) {
        for (let c = 0; c < column - 3; c++) {
            if (board[r][c] != ' ') {
                if (board[r][c] == board[r - 1][c + 1] && board[r - 1][c + 1] == board[r - 2][c + 2] && board[r - 2][c + 2] == board[r - 3][c + 3]) {
                    setwinner(r, c);
                    return;
                }
            }
        }
    }
}

function setwinner(r, c) {
    let win = document.getElementById("winner");
    if (board[r][c] == redplayer) {
        win.innerText = "Red win";
    }
    else {
        win.innerText = "Yellow win";
    }
}