## 💡 Funcionalidades

- Visualização de tarefas em formato de tabela
- Marcação de tarefas como concluídas
- Adição de novas tarefas

## 🚀 Como Executar

```bash
# Instalar dependências
npm install

# Iniciar o servidor em modo de desenvolvimento
npm run dev

# OU iniciar o servidor normalmente
npm start
```

Acesse a aplicação em: http://localhost:3000/tasks

## 📋 Estrutura da Aplicação

### Backend (app.js)

O backend utiliza Express e EJS para renderização de páginas. As tarefas atualmente são mantidas em memória (sem persistência em banco de dados).

```javascript
const express = require("express");
const app = express();

app.set("view engine", "ejs");
app.use(express.urlencoded({ extended: true }));

// Array para armazenar tarefas
let tasks = [
  { id: 1, name: "Estudar Node.js", completed: false },
  { id: 2, name: "Preparar aula", completed: true }
];

// Rota para exibir tarefas
app.get("/tasks", (req, res) => {
  res.render("index", { tasks });
});

// Rota para adicionar nova tarefa
app.post("/tasks", (req, res) => {
  const { name } = req.body;
  if (name) {
    tasks.push({ id: Date.now(), name, completed: false });
  }
  res.redirect("/tasks");
});

// Rota para marcar tarefa como concluída
app.post("/tasks/:id/complete", (req, res) => {
  const id = parseInt(req.params.id);
  tasks = tasks.map(task =>
    task.id === id ? { ...task, completed: true } : task
  );
  res.redirect("/tasks");
});

app.listen(3000, () => {
  console.log("Servidor online.");
});
```

### Frontend (views/index.ejs)

A interface apresenta uma tabela com as tarefas, seus status e ações disponíveis:

- Coluna **Task**: Nome da tarefa
- Coluna **Status**: Estado atual (pendente/concluída)
- Coluna **Action**: Botão para marcar como concluída
- Formulário para adicionar novas tarefas

## FRAMEWORK 

O FrameWork utulizado foi o Bulma, a baixo contém exemplos da estilização da págian .ejs

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d9102e49-860f-4c0e-9241-de5c1887dc04" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a7cd1e92-8f3b-4f6d-bc09-c2df1d3489e2" />


