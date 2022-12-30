let input_val = 0
serial.redirect(
    SerialPin.P0,
    SerialPin.P1,
    BaudRate.BaudRate115200
)
basic.forever(function () {
    input_val = parseInt(serial.readLine())
    led.plotBarGraph(
        input_val,
        1024
    )
})
