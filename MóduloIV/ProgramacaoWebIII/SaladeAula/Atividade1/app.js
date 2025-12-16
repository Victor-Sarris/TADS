const express = require('express');
const app = express();
const usuariosRouter = require('./routes/usuarios'); 

app.set('view engine', 'ejs'); 

// --- EXERCÍCIO 2: Middleware de Log ---
// Exibe no console a URL acessada e a hora da requisição
app.use((req, res, next) => {
    console.log(`[${new Date().toLocaleTimeString()}] Acesso a URL: ${req.url}`);
    next();
});

// --- EXERCÍCIO 1: Rotas Básicas ---
// Rota / -> Retorna "Página inicial"
app.get('/', (req, res) => {
    res.send("Página inicial");
});

// Rota /produtos -> Retorna HTML (Ex 1 e integração com Ex 11/12) [cite: 30, 31, 48, 49]
app.get('/produtos', (req, res) => {
    const listaProdutos = [
        { nome: "Notebook", preco: 2500 },
        { nome: "Mouse", preco: 50 },
        { nome: "Teclado", preco: 100 }
    ];
    res.render('produtos', { produtos: listaProdutos });
});

// Rota /contato -> Retorna JSON 
app.get('/contato', (req, res) => {
    res.json({ nome: "Seu Nome", email: "seuemail@exemplo.com" });
});

// --- EXERCÍCIO 3: API de Produtos (JSON) 
app.get('/api/produtos', (req, res) => {
    const dados = [
        { id: 1, item: "Monitor", estoque: 10 },
        { id: 2, item: "Cadeira", estoque: 5 }
    ];
    res.json(dados);
});

// --- EXERCÍCIO 4: Parâmetro URL em Maiúsculas 
app.get('/texto/:palavra', (req, res) => {
    const palavra = req.params.palavra.toUpperCase();
    res.send(palavra);
});

// --- EXERCÍCIO 5: Rota Aluno com Parâmetros 
app.get('/aluno/:nome/:idade', (req, res) => {
    const { nome, idade } = req.params;
    res.send(`O aluno ${nome} tem ${idade} anos.`);
});

// --- EXERCÍCIO 6 e 7: Busca com Query String e Tratamento de Erro 
app.get('/busca', (req, res) => {
    const valor = req.query.q;
    
    // Tratamento de erro se o parâmetro não for informado 
    if (!valor) {
        return res.status(400).send("Erro: Parâmetro de busca 'q' não informado. Tente /busca?q=algo");
    }
    
    res.send(`Você buscou por: ${valor}`);
});

// --- EXERCÍCIO 8: Soma de dois números 
app.get('/soma/:a/:b', (req, res) => {
    const a = parseFloat(req.params.a);
    const b = parseFloat(req.params.b);

    if (isNaN(a) || isNaN(b)) {
        return res.status(400).send("Erro: Forneça dois números válidos.");
    }

    res.send(`O resultado da soma é: ${a + b}`);
});

// --- EXERCÍCIO 13: Template Pagina Genérica 
app.get('/pagina', (req, res) => {
    res.render('pagina', { 
        titulo: "Minha Página Dinâmica", 
        mensagem: "Bem-vindo ao sistema criado com Express e EJS!" 
    });
});

// --- EXERCÍCIO 9: Configuração do Router de Usuários 
app.use('/usuarios', usuariosRouter);

// Iniciar servidor
app.listen(3000, () => {
    console.log('Servidor rodando em http://localhost:3000');
});