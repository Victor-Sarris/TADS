import { DataTypes } from "sequelize";
import conectDB from "../database/db";
import User from "./User.js";

const sequelize = await conectDB();

const Professional = sequelize.define("Professional", {
  id: {
    type: DataTypes.STRING,
    allowNull: false,
    primaryKey: true,
    autoIncrement: true,
  },
  crp: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  speciality: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  approach: {
    type: DataTypes.STRING,
  },
  description: {
    type: DataTypes.TEXT,
  },
  // chave estrangeira ligada ao modelo do 'User'
  userId: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: User,
      key: "id",
    },
  },
});

// relacionamento: um User tem o Perfil do Profissional
User.hasOne(Professional, { foreignKey: "userId" });
Professional.belongsTo(User, { foreignKey: "userId" });

export default Professional;
