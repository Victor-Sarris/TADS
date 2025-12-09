const http = require("http") // chamando module node.js
const host = "192.168.18.110" //localhost
// const host = "127.0.0.1" 
const port = "3000" // porta do servidor

// criação de função anônima
// numa função anônima é preciso o requerimento (req) e a resposta (res) ao servidor http
const servidor = http.createServer((req, res)=>{ 
    // 200 => quando o servidor responde que está tudo ok
    res.statusCode = 200; 
    // tipo de conteudo que o servidor vai buscar
    res.setHeader('Content-Type', 'Text/Plain');
    // conteudo do site
    res.end("Hello Word!"); 
})

servidor.listen(port, host,()=>{
    console.log(`Servidor on-line: http://${host}:${port}`)
})