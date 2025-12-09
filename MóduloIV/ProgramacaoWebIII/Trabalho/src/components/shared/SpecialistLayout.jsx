// src/components/shared/SpecialistLayout.jsx
import React from "react";
import { Outlet } from "react-router-dom";
import SpecialistSidebar from "./Sidebar/SpecialisSidebar";

export default function SpecialistLayout() {
  const userData = {
    name: "Dr. João Silva",
    email: "joao.silva@email.com",
  };

  return (
    <div className="flex h-screen">
      <SpecialistSidebar userData={userData} />
      <div className="flex-1 overflow-auto bg-gray-50">
        <Outlet />
      </div>
    </div>
  );
}