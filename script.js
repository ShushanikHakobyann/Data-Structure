function runDemo() {

    let option = document.getElementById("option").value;
    let src = document.getElementById("source").value;
    let dest = document.getElementById("destination").value;
    let k = document.getElementById("k").value;

    let output = "";

    if (option == "1") {
        output = "Cheapest Route:\n" +
            src + " → Istanbul → " + dest +
            "\nCost: 320 EUR";
    }

    else if (option == "2") {
        output = "Fastest Route:\n" +
            src + " → Dubai → " + dest +
            "\nTime: 6h 40m";
    }

    else if (option == "3") {
        output = "Reachable Airports from " + src +
            " within " + k + " stops:\n" +
            "Istanbul, Rome, Dubai, Paris";
    }

    else if (option == "4") {
        output = "Critical Airports:\nIstanbul, Frankfurt, Dubai";
    }

    document.getElementById("output").innerText = output;
}