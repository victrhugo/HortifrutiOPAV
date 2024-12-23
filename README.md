<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Hortifruti OVAP - Sistema de Estoque</title>
</head>
<body>

<h1>Hortifruti OVAP - Sistema de Estoque</h1>

<h2>Descrição</h2>
<p>O <strong>Hortifruti OVAP - Sistema de Estoque</strong> é uma aplicação para gerenciar produtos de hortifruti, permitindo o controle de itens em estoque com ações essenciais de cadastro, listagem, validação e exclusão de produtos.</p>

<h2>Funcionalidades</h2>
<ul>
    <li><strong>Cadastrar Produto</strong>: Permite adicionar novos produtos ao estoque.</li>
    <li><strong>Listar Produtos</strong>: Exibe uma lista de todos os produtos cadastrados.</li>
    <li><strong>Excluir Produto por ID</strong>: Remove produtos específicos com base no ID.</li>
</ul>

<h2>Tecnologias Utilizadas</h2>
<ul>
    <li><strong>Linguagem</strong>: C Orientada a objetos.</li>
</ul>

<h1>Requisitos do Sistema de Estoque Hortifruti</h1>
    
<h2>Requisitos Funcionais</h2>
    <ul>
        <li><strong>Cadastro de Produto</strong>:
            <ul>
                <li>O sistema deve permitir o cadastro de novos produtos.</li>
                <li>Cada produto deve possuir um identificador único (ID), nome, categoria, preço de venda e quantidade em estoque.</li>
                <li>O sistema deve validar os dados inseridos pelo usuário, garantindo que todos os campos obrigatórios estejam preenchidos e que a quantidade e o preço estejam dentro de limites razoáveis.</li>
            </ul>
        </li>
        <li><strong>Listagem de Produtos</strong>:
            <ul>
                <li>O sistema deve permitir a listagem de todos os produtos cadastrados.</li>
                <li>A listagem deve exibir informações como ID, nome, categoria, quantidade e preço de cada produto.</li>
                <li>O sistema deve permitir a filtragem dos produtos por categoria ou ordenação por nome, preço ou quantidade.</li>
            </ul>
        </li>
        <li><strong>Exclusão de Produto</strong>:
            <ul>
                <li>O sistema deve permitir a exclusão de produtos a partir do ID fornecido.</li>
                <li>O sistema deve solicitar confirmação antes de excluir um produto.</li>
                <li>Em caso de erro (como um ID inexistente), o sistema deve notificar o usuário.</li>
            </ul>
        </li>
        <li><strong>Sair do Sistema</strong>:
            <ul>
                <li>O sistema deve fornecer uma opção para que o usuário saia do sistema de forma segura.</li>
                <li>Antes de sair, o sistema deve salvar todos os dados atualizados para evitar perdas.</li>
            </ul>
        </li>
    </ul>

<h2>Requisitos Não Funcionais</h2>
    <ul>
        <li><strong>Usabilidade</strong>:
            <ul>
                <li>A interface do sistema deve ser amigável e fácil de usar, com uma navegação intuitiva.</li>
                <li>As mensagens de erro devem ser claras, indicando ao usuário o que precisa ser corrigido.</li>
            </ul>
        </li>
        <li><strong>Desempenho</strong>:
            <ul>
                <li>O sistema deve processar as operações de cadastro, listagem e exclusão em tempo real, com uma resposta rápida para o usuário.</li>
                <li>O tempo de resposta para operações de consulta e listagem deve ser inferior a 2 segundos, mesmo com uma base de dados de até 1.000 produtos.</li>
            </ul>
        </li>
        <li><strong>Segurança</strong>:
            <ul>
                <li>O sistema deve garantir a integridade dos dados, prevenindo operações mal-intencionadas.</li>
                <li>A exclusão de produtos deve exigir uma confirmação explícita.</li>
            </ul>
        </li>
        <li><strong>Portabilidade</strong>:
            <ul>
                <li>O sistema deve ser capaz de rodar em diferentes sistemas operacionais (como Windows, Linux e macOS).</li>
                <li>Ele deve ser desenvolvido em uma linguagem multiplataforma (como Java) para garantir essa compatibilidade.</li>
            </ul>
        </li>
        <li><strong>Escalabilidade</strong>:
            <ul>
                <li>O sistema deve ser escalável, permitindo aumentar a capacidade de produtos cadastrados sem comprometer o desempenho.</li>
                <li>O sistema deve suportar futuros módulos, como um controle de fornecedores ou um histórico de movimentações do estoque.</li>
            </ul>
        </li>
        <li><strong>Manutenibilidade</strong>:
            <ul>
                <li>O código deve ser estruturado e documentado para facilitar futuras manutenções.</li>
                <li>Boas práticas de programação e organização modular devem ser seguidas.</li>
            </ul>
        </li>
    </ul>

