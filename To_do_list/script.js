const inputTask = document.getElementById("input_task");
const listContainer = document.getElementById("task_list");

let span = document.createElement("span");
span.innerHTML = "\u00d7";
function addtask() {
    if (inputTask.value === '') {
        alert("Write something!");
    }
    else {
        let li = document.createElement("li");
        let i = document.createElement("i");

        let uniqueId = 'icon' + Date.now();

        i.className = "fa-regular fa-circle";
        i.id = uniqueId;
        i.setAttribute("onclick", `change('${uniqueId}')`);

        li.appendChild(i);
        li.appendChild(document.createTextNode(" " + inputTask.value));

        listContainer.appendChild(li);

        let span = document.createElement("span");
        span.innerHTML = "\u00d7";
        span.setAttribute("onclick", "remove_task(this)");
        li.appendChild(span);

    }
    inputTask.value = "";
    save_data();
}

function change(element) {
    let icon = document.getElementById(element);
    if (icon.className === "fa-regular fa-circle") {
        icon.className = "fa-regular fa-circle-check";
    } else {
        icon.className = "fa-regular fa-circle";
    }
    save_data();
}

function remove_task(element) {
    element.parentElement.remove();
    save_data();
}

function save_data() {
    localStorage.setItem("data", listContainer.innerHTML);
}
show_task();
function show_task() {
    listContainer.innerHTML = localStorage.getItem("data");
}
//   localStorage.removeItem("data");